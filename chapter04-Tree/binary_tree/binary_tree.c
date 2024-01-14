#include "binary_tree.h"


Node* createNode(ElementType data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
}

void destroyNode(Node* node){
    free(node);
}

void destroyTree(Node* node){
    if(node != NULL)
        return;
    
    destroyTree(node->left);
    destroyTree(node->right);

    destroyNode(node);
}

void preorderPrintTree(Node* node){
    if(node == NULL)
        return;
    
    printf(" %c", node->data);

    preorderPrintTree(node->left);
    preorderPrintTree(node->right);

}

void inorderPrintTree(Node* node){
    if(node == NULL)
        return;

    inorderPrintTree(node->left);
    printf(" %c", node->data);
    inorderPrintTree(node->right);
}

void postorderPrintTree(Node* node){
    if(node == NULL)
        return;

    postorderPrintTree(node->left);
    postorderPrintTree(node->right);
    printf(" %c", node->data);
}
