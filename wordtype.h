// COMP348 Section AA
// Student Name: Mingming Zhang
// Student ID:40258080

#ifndef WORDTYPE_H
#define WORDTYPE_H

// Prototypes for word filtering and skip checks
void filter_word(const char *input, char *output, const char *wtype);
int should_skip(const char *word, char **skipwords, int skip_count);

#endif

