#include "left_child_right_sibling.h"


Node* createNode(ElementType data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->left_child = NULL;
    node->right_sibling = NULL;
    node->data = data;

    return node;
}

void destroyNode(Node* node){
    free(node);
}

void destroyTree(Node* root){
    if(root->right_sibling != NULL)
        destroyTree(root->right_sibling);
    
    if(root->left_child != NULL)
        destroyTree(root->left_child);

    root->left_child = NULL;
    root->right_sibling = NULL;

    destroyNode(root);
}

void addChildNode(Node* parent, Node* child){
    if(parent->left_child == NULL)
        parent->left_child = child;
    else{
        Node* temp = parent->left_child;
        while(temp->right_sibling != NULL){
            temp = temp->right_sibling;
        }

        temp->right_sibling = child;
    }
}

void printTree(Node* node, int depth){
    int i = 0;
    for(i = 0; i < depth + 1; i++)
        printf("   ");
    
    if(depth > 0)
        printf("+--");

    printf("%c\n", node->data);

    if(node->left_child != NULL)
        printTree(node->left_child, depth + 1);
    
    if(node->right_sibling != NULL)
        printTree(node->right_sibling, depth);
}


void printNodesAtLevel(Node* root, int level){
    int depth = 1;
    Node* temp = root;
    while(depth != level){
        temp = temp->left_child;
        depth++;
    }

    while(temp != NULL){
        if(temp->left_child != NULL){
            Node* child = temp->left_child;
            while(child != NULL){
                printf("%c\n", child->data);
                child = child->right_sibling;
            }
        }

        temp = temp->right_sibling;
    }
}