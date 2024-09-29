// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#ifndef OUTPUT_H
#define OUTPUT_H

// Prototypes for sorting and printing words
void sort_words(char **words, int word_count, int ascending);
int compare_asc(const void *a, const void *b);
int compare_desc(const void *a, const void *b);
void print_words(char **words, int word_count);

#endif


