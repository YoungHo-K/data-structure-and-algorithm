#include <math.h>
#include <stdio.h>
#include "karp_rabin.h"


int karpRabin(char* text, int text_size, int start, char* pattern, int pattern_size){
    int i = 0;
    int j = 0;
    int coefficient  = pow(2, pattern_size - 1);
    int hash_text    = hash(text, pattern_size);
    int hash_pattern = hash(pattern, pattern_size);

    for(i = start; i <= text_size - pattern_size; i++){
        hash_text = reHash(text, i, pattern_size, hash_text, coefficient);

        if(hash_pattern == hash_text){
            for(j = 0; j < pattern_size; j++){
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j >= pattern_size)
                return i;
        }
    }

    return -1;
}

int hash(char* string, int size){
    int i = 0;
    int hash_value = 0;

    for(i = 0; i < size; i++){
        hash_value = string[i] + (hash_value * 2);
    }

    return hash_value;
}

int reHash(char* string, int start, int size, int hash_prev, int coefficient){
    if(start == 0)
        return hash_prev;

    return string[start + size - 1] + ( (hash_prev - coefficient * string[start - 1]) * 2 );
}