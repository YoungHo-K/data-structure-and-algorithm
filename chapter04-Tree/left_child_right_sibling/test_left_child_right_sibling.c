#include "left_child_right_sibling.h"


int main(void){
    Node* root = createNode('A');

    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');
    Node* G = createNode('G');
    Node* H = createNode('H');
    Node* I = createNode('I');
    Node* J = createNode('J');
    Node* K = createNode('K');

    addChildNode(root, B);
        addChildNode(B, C);
        addChildNode(B, D);
            addChildNode(D, E);
            addChildNode(D, F);

    addChildNode(root, G);
        addChildNode(G, H);

    addChildNode(root, I);
        addChildNode(I, J);
            addChildNode(J, K);

    printTree(root, 0);
    printNodesAtLevel(root, 2);

    destroyTree(root);

    return 0;
}