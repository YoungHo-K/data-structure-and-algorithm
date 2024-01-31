#include <stdlib.h>
#include "knuth_morris_pratt.h"


void preprocess(char* pattern, int pattern_size, int* border){
    int i = 0;
    int j = -1;

    border[0] = -1;

    while(i < pattern_size){
        while(j > -1 && pattern[i] != pattern[j])
            j = border[j];
        
        i++;
        j++;

        border[i] = j;
    }
}

int knuthMorrisPratt(char* text, int text_size, int start, char* pattern, int pattern_size){
    int i = start;
    int j = 0;
    int position = -1;

    int* border = (int*)calloc(pattern_size + 1, sizeof(int));

    preprocess(pattern, pattern_size, border);

    while(i < text_size){
        while(j >= 0 && text[i] != pattern[j])
            j = border[j];
        
        i++;
        j++;

        if(j == pattern_size){
            position = i - j;
            break;
        }
    }

    free(border);

    return position;
}