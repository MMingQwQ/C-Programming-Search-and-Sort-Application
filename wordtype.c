// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#include <ctype.h>
#include <string.h>
#include "wordtype.h"

// Function to filter characters in a word based on the specified word type
void filter_word(const char *input, char *output, const char *wtype) {
    int index = 0;
    if (strcmp(wtype, "ALPHA") == 0) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (isalpha(input[i])) {
                output[index++] = input[i];
            } else {
                output[index++] = ' ';
            }
        }
        output[index] = '\0'; 
    } else if (strcmp(wtype, "ALPHANUM") == 0) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (isalnum(input[i])) {
                output[index++] = input[i];
            } else {
                output[index++] = ' ';
            }
        }
        output[index] = '\0';
    } else if (strcmp(wtype, "ALL") == 0) {
        strcpy(output, input);
    }
}

// Function to check if a word should be skipped
int should_skip(const char *word, char **skipwords, int skip_count) {
    for (int i = 0; i < skip_count; i++) {
        if (strcmp(word, skipwords[i]) == 0) {
            return 1;  // Return true if the word matches a skip word
        }
    }
    return 0;  // Return false if the word should not be skipped
}


