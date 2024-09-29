// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"
#include "wordtype.h"
#include "output.h"

// Function to print an error message and exit with the given error code
void error_exit(const char *message, int error_code) {
    fprintf(stderr, "%s\n", message);
    exit(error_code);
}

int main(int argc, char *argv[]) {
    // Check if the minimum number of arguments is provided
    if (argc < 4) {
        error_exit("Usage: ssort <inputfile> <n> <wtype> [<sorttype> [<skipword1> <skipword2> ...]]", 1);
    }

    const char *filename = argv[1];  // Input file name
    int n = atoi(argv[2]);  // Maximum number of words to read
    if (n <= 0) {
        error_exit("Invalid array size,please enter a positive integer", 1);
    }

    const char *wtype = argv[3];  // Word type (ALPHA, ALPHANUM, ALL)
    if (wtype == NULL || (strcmp(wtype, "ALPHA") != 0 && strcmp(wtype, "ALPHANUM") != 0 && strcmp(wtype, "ALL") != 0)) {
        error_exit("Invalid or missing word type. Valid types are: ALPHA, ALPHANUM, ALL", 2);
    }

    const char *sorttype = (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) ? argv[4] : "ASC";
    int ascending = strcmp(sorttype, "DESC") != 0;  // Determine sorting order
    int sort_arg_index = (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) ? 5 : 4;

    
    char **skipwords = (char **)malloc((argc - sort_arg_index) * sizeof(char *));
    int skip_count = 0;
    for (int i = sort_arg_index; i < argc; i++) {
        skipwords[skip_count++] = argv[i];
    }

    
    char **words = (char **)malloc(n * sizeof(char *));
    int word_count;

    // Read up to n words from the file
    read_words(filename, words, &word_count, n, wtype);

    /* Debug: Print words read
    printf("Words read:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }*/

    
    char **filtered_words = (char **)malloc(word_count * sizeof(char *));
    int filtered_count = filter_words(words, word_count, skipwords, skip_count, filtered_words, wtype);

    /* Debug: Print filtered words
    printf("Filtered words:\n");
    for (int i = 0; i < filtered_count; i++) {
        printf("%s\n", filtered_words[i]);
    }*/

    // Sort the filtered words
    sort_words(filtered_words, filtered_count, ascending);

    // Print the sorted words
    print_words(filtered_words, filtered_count);

    // Free allocated memory
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    
    free(words);
    
    free(skipwords);
    
    for (int i = 0; i < filtered_count; i++) {
        free(filtered_words[i]);
    }
    
    free(filtered_words);

    return 0;
}

