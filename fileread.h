// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#ifndef FILEREAD_H
#define FILEREAD_H

// Prototypes for reading and filtering words
void read_words(const char *filename, char **words, int *word_count, int max_words, const char *wtype);
int filter_words(char **input_words, int word_count, char **skipwords, int skip_count, char **filtered_words, const char *wtype);

#endif

