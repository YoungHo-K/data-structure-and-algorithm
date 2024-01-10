#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode{
    char* data;
    struct tagNode* next_node;
} Node;

typedef struct tagLinkedQueue{
    Node* front;
    Node* rear;
    int count;
} LinkedQueue;


void createQueue(LinkedQueue** queue);
void destroyQueue(LinkedQueue* queue);
Node* createNode(char* data);
void destroyNode(Node* node);
void enqueue(LinkedQueue* queue, Node* node);
Node* dequeue(LinkedQueue* queue);
int isEmpty(LinkedQueue* queue);

#endif
