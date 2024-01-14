#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagNode{
    struct tagNode* left;
    struct tagNode* right;
    ElementType data;
} Node;


Node* createNode(ElementType data);
void  destroyNode(Node* node);
void  destroyTree(Node* node);

void  preorderPrintTree(Node* node);
void  inorderPrintTree(Node* node);
void  postorderPrintTree(Node* node);

void  buildExpressionTree(char* postfix_expression, Node** node);
double evaluate(Node* tree);

#endif