#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
} Node;

typedef struct tagArrayStack {
    int capacity;
    int top;
    Node* nodes;
} ArrayStack;


void createStack(ArrayStack** stack, int capacity);
void destroyStack(ArrayStack* stack);
void push(ArrayStack* stack, ElementType data);
ElementType pop(ArrayStack* stack);
ElementType top(ArrayStack* stack);
int getSize(ArrayStack* stack);
int isEmpty(ArrayStack* stack);

#endif