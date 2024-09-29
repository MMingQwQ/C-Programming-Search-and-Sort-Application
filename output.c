// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"

// Function to sort words 
void sort_words(char **words, int word_count, int ascending) {
    qsort(words, word_count, sizeof(char *), ascending ? compare_asc : compare_desc);
}

/*strcmp(*str1,*str2) compares two strings in dirctionary order
return negative value if *str1 is less than *str2
return zero if they are equal
return positive value if *str1 is greater than *str2
*/


// Comparison function for ascending order
int compare_asc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Comparison function for descending order
int compare_desc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

// Function to print words, 10 per line
void print_words(char **words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s", words[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");  // Print a newline after every 10th word
        } else {
            printf(" ");  // Space between words
        }
    }
    printf("\n");
}


