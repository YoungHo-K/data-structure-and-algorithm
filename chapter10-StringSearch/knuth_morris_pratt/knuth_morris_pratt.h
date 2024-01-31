#ifndef KNUTH_MORRIS_PRATT_H
#define KNUTH_MORRIS_PRATT_H

#include <stdio.h>

int  knuthMorrisPratt(char* text, int text_size, int start, char* pattern, int pattern_size);
void preprocess(char* pattern, int pattern_size, int* border);

#endif
