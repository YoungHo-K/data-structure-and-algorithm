#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
    struct tagNode* prev_node;
    struct tagNode* next_node;
} Node;

Node* CreateNode(ElementType data);
void DestroyNode(Node* node);
void AppendNode(Node** head, Node* new_node);
void InsertAfter(Node* current, Node* new_node);
void RemoveNode(Node** head, Node* node);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);
void PrintNode(Node* node);
void PrintReverse(Node* head);

#endif

