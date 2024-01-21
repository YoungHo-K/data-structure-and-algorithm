#ifndef CHAINING_H
#define CHAINING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode{
    KeyType key;
    ValueType value;

    struct tagNode* next;
} Node;

typedef Node* List;

typedef struct tagHashTable{
    int table_size;
    List* table;
} HashTable;

HashTable* createHashTable(int table_size);
void       destroyHashTable(HashTable* ht);

Node*      createNode(KeyType key, ValueType value);
void       destroyNode(Node* node);

void       destroyList(List the_list);

void       set(HashTable* ht, KeyType key, ValueType value);
ValueType  get(HashTable* ht, KeyType key);
int        hash(KeyType key, int key_length, int table_size);

#endif