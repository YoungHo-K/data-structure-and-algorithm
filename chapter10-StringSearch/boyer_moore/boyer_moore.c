#include <stdlib.h>
#include "boyer_moore.h"


int boyerMoore(char* text, int text_size, int start, char* pattern, int pattern_size){
    int  bad_char_table[128];
    int* good_suff_table = (int*)calloc(pattern_size + 1, sizeof(int));
    int* pos_of_border = (int*)calloc(pattern_size + 1, sizeof(int));

    int i = start;
    int j = 0;
    int position = -1;

    buildBCT(pattern, pattern_size, bad_char_table);
    buildGST(pattern, pattern_size, pos_of_border, good_suff_table);

    while(i <= text_size - pattern_size){
        j = pattern_size - 1;
        while(j >= 0 && pattern[j] == text[i + j])
            j--;

        if(j < 0){
            position = i;
            break;
        }
        else{
            i += max(good_suff_table[j + 1], j - bad_char_table[text[i + j]]);
        }
    }

    free(pos_of_border);
    free(good_suff_table);

    return position;
}

void buildBCT(char* pattern, int pattern_size, int* bad_char_table){
    int i;
    int j;

    for(i = 0; i < 128; i++)
        bad_char_table[i] = -1;

    for(j = 0; j < pattern_size; j++)
        bad_char_table[pattern[j]] = j;
}

void buildGST(char* pattern, int pattern_size, int* pos_of_border, int* good_suff_table){
    int i = pattern_size;
    int j = pattern_size + 1;

    pos_of_border[i] = j;
    while(i > 0){
        while(j <= pattern_size && pattern[i - 1] != pattern[j - 1]){
            if(good_suff_table[j] == 0)
                good_suff_table[j] = j - i;
            
            j = pos_of_border[j];
        }

        i--;
        j--;

        pos_of_border[i] = j;
    }

    j = pos_of_border[0];
    for(i = 0; i <= pattern_size; i++){
        if(good_suff_table[i] == 0)
            good_suff_table[i] = j;
        
        if(i == j)
            j = pos_of_border[j];
    }
}

int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}