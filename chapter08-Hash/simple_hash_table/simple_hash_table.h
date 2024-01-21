#ifndef SIMPLE_HASH_TABLE_H
#define SIMPLE_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode{
    KeyType key;
    ValueType value;
} Node;

typedef struct tagHashTable{
    int table_size;
    Node* table;
} HashTable;


HashTable* createHashTable(int table_size);
void       set(HashTable* table, KeyType key, ValueType value);
ValueType  get(HashTable* table, KeyType key);
void       destroyHashTable(HashTable* table);
int        hash(KeyType key, int table_size);

#endif
