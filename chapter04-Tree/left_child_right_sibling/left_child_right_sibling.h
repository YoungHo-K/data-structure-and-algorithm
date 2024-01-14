#ifndef LEFT_CHILD_RIGHT_SIBLING_H
#define LEFT_CHILD_RIGHT_SIBLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagNode{
    struct tagNode* left_child;
    struct tagNode* right_sibling;
    ElementType data;
} Node;

Node* createNode(ElementType data);
void  destroyNode(Node* node);
void  destroyTree(Node* root);

void  addChildNode(Node* parent, Node* child);
void  printTree(Node* node, int depth);
void  printNodesAtLevel(Node* root, int level);

#endif