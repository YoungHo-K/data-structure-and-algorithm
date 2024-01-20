#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType data;
} Node;

typedef struct tagHeap{
    Node* nodes;
    int capacity;
    int used_size;
} Heap;

Heap* create(int initial_size);
void  destroy(Heap* heap);
void  insert(Heap* heap, ElementType data);
void  deleteMin(Heap* heap, Node* root);
int   getParent(int index);
int   getLeftChild(int index);
void  swapNodes(Heap* heap, int index1, int index2);
void  printNodes(Heap* heap);

#endif
