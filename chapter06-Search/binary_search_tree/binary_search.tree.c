#include "binary_search_tree.h"


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

void destroyTree(Node* tree){
    if(tree->left != NULL)
        destroyTree(tree->left);
    
    if(tree->right != NULL)
        destroyTree(tree->right);

    tree->left = NULL;
    tree->right = NULL;

    destroyNode(tree);
}

Node* searchNode(Node* tree, ElementType target){
    if(tree == NULL)
        return NULL;
    
    if(tree->data == target)
        return tree;
    
    else if(tree->data < target)
        return searchNode(tree->right, target);
    
    else
        return searchNode(tree->left, target);
}

Node* searchMinNode(Node* tree){
    if(tree == NULL)
        return NULL;
    
    if(tree->left == NULL)
        return tree;
    else
        return searchMinNode(tree->left);
}

void insertNode(Node* tree, Node* child){
    if(tree->data < child->data){
        if(tree->right == NULL)
            tree->right = child;
        else
            insertNode(tree->right, child);
    }
    else if(tree->data > child->data){
        if(tree->left == NULL)
            tree->left = child;
        else
            insertNode(tree->left, child);
    }
}

Node* removeNode(Node* tree, Node* parent, ElementType target){
    Node* removed = NULL;

    if(tree == NULL)
        return NULL;
    
    if(tree->data < target)
        removed = removeNode(tree->right, tree, target);
    else if(tree->data > target)
        removed = removeNode(tree->left, tree, target);
    else{
        removed = tree;

        if(tree->left == NULL && tree->right == NULL){
            if(parent->left == tree)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else{
            if(tree->left != NULL && tree->right != NULL){
                Node* min_node = searchMinNode(tree->right);
                min_node = removeNode(tree, NULL, min_node->data);
                tree->data = min_node->data;
            }
            else{
                Node* temp = NULL;
                if(tree->left != NULL)
                    temp = tree->left;
                else
                    temp = tree->right;

                if(parent->left == tree)
                    parent->left = temp;
                else
                    parent->right = temp;
            }
        }
    }

    return removed;
}

void inorderPrintTree(Node* node){
    if(node == NULL)
        return;
    
    inorderPrintTree(node->left);
    printf("%d ", node->data);
    inorderPrintTree(node->right);
}
