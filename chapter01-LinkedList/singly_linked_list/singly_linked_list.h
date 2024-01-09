#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
    struct tagNode* next_node;
} Node;

Node* CreateNode(ElementType data);
void DestroyNode(Node* node);
void DestroyAllNodes(Node** head);
void AppendNode(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* new_node);
void InsertBefore(Node** head, Node* current, Node* new_head);
void InsertNewHead(Node** head, Node* new_head);
void RemoveNode(Node** head, Node* node);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);

#endif

