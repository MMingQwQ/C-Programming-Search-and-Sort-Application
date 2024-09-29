// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordtype.h"
#include "fileread.h"

// Function to read words from a file and store them in the array
void read_words(const char *filename, char **words, int *word_count, int max_words, const char *wtype) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    size_t buffer_size = 0;
    char *line = NULL;  // getline will allocate the buffer dynamically
    *word_count = 0;

    // Read each line from the file
    while (*word_count < max_words && getline(&line, &buffer_size, file) != -1) {
        char filtered_line[buffer_size * 2];
        filter_word(line, filtered_line, wtype);  // Filter the line based on the word type

        char *token = strtok(filtered_line, " \t\n\v\f\r,");
        while (token != NULL) {
            if (*word_count >= max_words) {
                break;
            }
            // Allocate memory and store the word
            words[*word_count] = strdup(token);
            (*word_count)++;
            token = strtok(NULL, " \t\n\v\f\r,");  // Get the next token
        }
    }

    free(line);
    fclose(file);
}

// Function to filter words based on the specified word type
int filter_words(char **input_words, int word_count, char **skipwords, int skip_count, char **filtered_words, const char *wtype) {
    int filtered_count = 0;

    for (int i = 0; i < word_count; i++) {
        
        char *filtered_word = (char *)malloc((strlen(input_words[i]) + 1) * sizeof(char));
        if (!filtered_word) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }

        filter_word(input_words[i], filtered_word, wtype);  // Filter the word based on the word type

        /* Debug: Print each input word and its filtered result
        printf("Input: %s, Filtered: %s\n", input_words[i], filtered_word); */

        // If the filtered word is not empty and valid, add it to the filtered words array
        if (strlen(filtered_word) > 0 && !should_skip(filtered_word, skipwords, skip_count)) {
            filtered_words[filtered_count] = strdup(filtered_word);
            filtered_count++;
        }

        free(filtered_word);  
    }

    return filtered_count;  // Return the count of filtered words
}

