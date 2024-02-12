#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct tagNode{
    PriorityType priority;
    void* data;
} Node;

typedef struct tagPriorityQueue{
    Node* nodes;
    int capacity;
    int used_size;
} PriorityQueue;

PriorityQueue* create(int initial_size);
void           destroy(PriorityQueue* q);
void           enqueue(PriorityQueue* q, Node node);
void           dequeue(PriorityQueue* q, Node* root);
int            getParent(int index);
int            getLeftChild(int index);
void           swapNodes(PriorityQueue* q, int index1, int index2);
int            isEmpty(PriorityQueue* q);

#endif
