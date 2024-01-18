#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct tagNode{
    struct tagNode* parent;
    struct tagNode* left;
    struct tagNode* right;

    enum {RED, BLACK} color;

    ElementType data;
} Node;


void  destroyTree(Node* Tree);

Node* createNode(ElementType data);
void  destroyNode(Node* node); 

Node* searchNode(Node* tree, ElementType target);
Node* searchMinNode(Node* tree);
void  insertNode(Node** tree, Node* node);
void  insertNodeHelper(Node** tree, Node* node);
Node* removeNode(Node** root, ElementType target);
void  rebuildAfterInsert(Node** tree, Node* node);
void  rebuildAfterRemove(Node** root, Node* node);

void  printTree(Node* node, int depth, int black_count);
void  rotateLeft(Node** root, Node* parent);
void  rotateRight(Node** root, Node* parent);

#endif