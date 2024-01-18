#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    struct tagNode* left;
    struct tagNode* right;
    ElementType data;
} Node;

Node* createNode(ElementType data);
void  destroyNode(Node* node);
void  destroyTree(Node* tree);

Node* searchNode(Node* tree, ElementType target);
Node* searchMinNode(Node* tree);
void  insertNode(Node* tree, Node* child);
Node* removeNode(Node* tree, Node* parent, ElementType target);
void  inorderPrintTree(Node* node);

#endif
