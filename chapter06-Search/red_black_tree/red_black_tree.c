#include "red_black_tree.h"

extern Node* Nil;

Node* createNode(ElementType data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = BLACK;
    node->data = data;

    return node;
}

void destroyNode(Node* node){
    free(node);
}

void destroyTree(Node* tree){
    if(tree->right != Nil)
        destroyTree(tree->right);

    if(tree->left != Nil)
        destroyTree(tree->left);
    
    tree->right = NULL;
    tree->left = NULL;

    destroyNode(tree);
}

Node* searchNode(Node* tree, ElementType target){
    if(tree == Nil)
        return NULL;
    
    if(tree->data > target)
        return searchNode(tree->left, target);
    else if(tree->data < target)
        return searchNode(tree->right, target);
    else
        return tree;
}

Node* searchMinNode(Node* tree){
    if(tree == Nil)
        return NULL;

    if(tree->left == Nil)
        return tree;
    else
        return searchMinNode(tree->left);
}

void insertNode(Node** tree, Node* node){
    insertNodeHelper(tree, node);

    node->color = RED;
    node->left = Nil;
    node->right = Nil;

    rebuildAfterInsert(tree, node);
}

void insertNodeHelper(Node** tree, Node* node){
    if((*tree) == NULL)
        (*tree) = node;
    
    if((*tree)->data < node->data){
        if((*tree)->right == Nil){
            (*tree)->right = node;
            node->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->right, node);
    }
    else if((*tree)->data > node->data){
        if((*tree)->left == Nil){
            (*tree)->left = node;
            node->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->left, node);
    }
}

void rotateRight(Node** root, Node* parent){
    Node* left_child = parent->left;

    parent->left = left_child->right;
    if(left_child->right != Nil)
        left_child->right->parent = parent;
    
    left_child->parent = parent->parent;

    if(parent->parent == NULL)
        (*root) = left_child;
    else{
        if(parent == parent->parent->left)
            parent->parent->left = left_child;
        else
            parent->parent->right = left_child;
    }

    left_child->right = parent;
    parent->parent = left_child;
}

void rotateLeft(Node** root, Node* parent){
    Node* right_child = parent->right;

    parent->right = right_child->left;

    if(right_child->left != Nil)
        right_child->left->parent = parent;
    
    right_child->parent = parent->parent;

    if(parent->parent == NULL)
        (*root) = right_child;
    else{
        if(parent->parent->left == parent)
            parent->parent->left = right_child;
        else
            parent->parent->right = right_child;
    }

    right_child->left = parent;
    parent->parent = right_child;
}

void rebuildAfterInsert(Node** root, Node* node){
    while(node != (*root) && node->parent->color == RED){
        if(node->parent == node->parent->parent->left){
            Node* uncle = node->parent->parent->right;
            if(uncle->color == RED){
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;

                node = node->parent->parent;
            }
            else{
                if(node == node->parent->right){
                    node = node->parent;
                    rotateLeft(root, node);
                }
                else{
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;

                    rotateRight(root, node->parent->parent);
                }
            }        
        }
        else{
            Node* uncle = node->parent->parent->left;
            if(uncle->color == RED){
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;

                node = node->parent->parent;
            }
            else{
                if(node == node->parent->left){
                    node = node->parent;
                    rotateRight(root, node);
                }
                
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(root, node->parent->parent);
            }
        }
    }

    (*root)->color = BLACK;
}

Node* removeNode(Node** root, ElementType data){
    Node* removed = NULL;
    Node* successor = NULL;
    Node* target = searchNode((*root), data);

    if(target == NULL)
        return NULL;

    if(target->left == Nil || target->right == Nil)
        removed = target;
    else{
        removed = searchMinNode(target->right);
        target->data = removed->data;
    }

    if(removed->left != Nil)
        successor = removed->left;
    else
        successor = removed->right;

    successor->parent = removed->parent;

    if(removed->parent == NULL)
        (*root) = successor;
    else{
        if(removed == removed->parent->left)
            removed->parent->left = successor;
        else
            removed->parent->right = successor;
    }

    if(removed->color == BLACK)
        rebuildAfterRemove(root, successor);
    
    return removed;
}

void rebuildAfterRemove(Node** root, Node* successor){
    Node* sibling = NULL;

    while(successor->parent != NULL && successor->color == BLACK){
        if(successor == successor->parent->left){
            sibling = successor->parent->right;

            if(sibling->color == RED){
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateLeft(root, successor->parent);
            }
            else{
                if(sibling->left->color == BLACK && sibling->right->color == BLACK){
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else{
                    if(sibling->left->color == RED){
                        sibling->left->color = BLACK;
                        sibling->color = RED;

                        rotateRight(root, sibling);
                        sibling = successor->parent->right;
                    }

                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(root, successor->parent);
                    successor = (*root);
                }
            }
        }
        else{
            sibling = successor->parent->left;
            if(sibling->color == RED){
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateRight(root, successor->right);
            }
            else{
                if(sibling->right->color == BLACK && sibling->left->color == BLACK){
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else{
                    if(sibling->right->color == RED){
                        sibling->right->color = BLACK;
                        sibling->color = RED;

                        rotateLeft(root, sibling);
                        sibling = successor->parent->left;
                    }

                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(root, successor->parent);
                    successor = (*root);
                }
            }
        }
    }

    successor->color = BLACK;
}

void printTree(Node* node, int depth, int black_count){
    int i = 0;
    char c = 'X';
    int v = -1;
    char cnt[100];

    if(node == NULL || node == Nil)
        return;
    
    if(node->color == BLACK)
        black_count++;
    
    if(node->parent != NULL){
        v = node->parent->data;

        if(node->parent->left == node)
            c = 'L';
        else
            c = 'R';
    }

    if(node->left == Nil && node->right == Nil)
        sprintf(cnt, "-------- %d", black_count);
    else
        strncpy(cnt, "", sizeof(cnt));

    for(i = 0; i < depth; i++)
        printf(" ");

    printf("%d %s [%c, %d] %s\n", node->data, (node->color == RED)?"RED":"BLACK", c, v, cnt);

    printTree(node->left, depth + 1, black_count);
    printTree(node->right, depth + 1, black_count);
}