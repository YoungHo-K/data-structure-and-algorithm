#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType data;
} Node;

typedef struct tagCircularQueue{
    int capacity;
    int front;
    int rear;
    Node* nodes;
} CircularQueue;


void createQueue(CircularQueue** queue, int capacity);
void destroyQueue(CircularQueue* queue);
void enqueue(CircularQueue* queue, ElementType data);
ElementType dequeue(CircularQueue* queue);
int getSize(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
int isFull(CircularQueue* queue);

#endif