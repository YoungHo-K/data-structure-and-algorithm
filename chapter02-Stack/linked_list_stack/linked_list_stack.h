#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* data;
    struct tagNode* next_node;
} Node;



typedef struct tagLinkedListStack {
    Node* list;
    Node* top;
} LinkedListStack;


void createStack(LinkedListStack** stack);
void destroyStack(LinkedListStack* stack);

Node* createNode(char* new_data);
void destroyNode(Node* node);

void push(LinkedListStack* stack, Node* new_node);
Node* pop(LinkedListStack* stack);

Node* top(LinkedListStack* stack);
int getSize(LinkedListStack* stack);
int isEmpty(LinkedListStack* stack);

#endif