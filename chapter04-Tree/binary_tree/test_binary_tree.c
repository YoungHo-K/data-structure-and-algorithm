#include "binary_tree.h"


int main(void){
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');
    Node* G = createNode('G');

    A->left = B;
    B->left = C;
    B->right = D;

    A->right = E;
    E->left = F;
    E->right = G;

    printf("Preorder...\n");
    preorderPrintTree(A);
    printf("\n\n");

    printf("Inorder...\n");
    inorderPrintTree(A);
    printf("\n\n");

    printf("Postorder...\n");
    postorderPrintTree(A);
    printf("\n\n");

    destroyTree(A);

    return 0;
}