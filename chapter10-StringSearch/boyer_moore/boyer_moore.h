#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stdio.h>

int  boyerMoore(char* text, int text_size, int start, char* pattern, int pattern_size);
void buildGST(char* pattern, int pattern_size, int* suffix, int* gst);
void buildBCT(char* pattern, int pattern_size, int* bct);

int  max(int a, int b);

#endif
