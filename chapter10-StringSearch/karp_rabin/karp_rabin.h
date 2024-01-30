#ifndef KARP_RABIN_H
#define KARP_RABIN_H

int karpRabin(char* text, int text_size, int start, char* pattern, int pattern_size);
int hash(char* string, int size);
int reHash(char* string, int start, int size, int hash_prev, int coefficient);

#endif
