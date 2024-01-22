#ifndef OPEN_ADDRESSING_H
#define OPEN_ADDRESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus{
    EMPTY = 0,
    OCCUPIED = 1
};

typedef struct tagElementType{
    KeyType key;
    ValueType value;

    enum ElementStatus status;
} ElementType;

typedef struct tagHashTable{
    int occupied_count;
    int table_size;

    ElementType* table;
} HashTable;


HashTable* createHashTable(int table_size);
void       destroyHashTable(HashTable* ht);
void       clearElement(ElementType* element);

void       set(HashTable** ht, KeyType key, ValueType value);
ValueType  get(HashTable* ht, KeyType key);
int        hash(KeyType key, int key_length, int table_size);
int        hash2(KeyType key, int key_length, int table_size);

void       rehash(HashTable** ht);

#endif