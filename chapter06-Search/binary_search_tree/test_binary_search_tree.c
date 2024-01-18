#include "binary_search_tree.h"


void printSearchResult(int target, Node* result){
    if(result != NULL)
        printf("Found: %d\n", result->data);
    else
        printf("Not Found: %d\n", target);
}

int main(void){
    Node* tree = createNode(123);
    Node* node = NULL;

    insertNode(tree, createNode(22));
    insertNode(tree, createNode(9918));
    insertNode(tree, createNode(424));
    insertNode(tree, createNode(17));
    insertNode(tree, createNode(3));

    insertNode(tree, createNode(98));
    insertNode(tree, createNode(34));

    insertNode(tree, createNode(760));
    insertNode(tree, createNode(317));
    insertNode(tree, createNode(1));

    int target = 17;
    node = searchNode(tree, target);
    printSearchResult(target, node);

    target = 117;
    node = searchNode(tree, target);
    printSearchResult(target, node);

    inorderPrintTree(tree);
    printf("\n");

    printf("Removing 98...\n");

    node = removeNode(tree, NULL, 98);
    destroyNode(node);

    inorderPrintTree(tree);
    printf("\n");

    printf("Inserting 111...\n");

    insertNode(tree, createNode(111));
    inorderPrintTree(tree);
    printf("\n");

    destroyTree(tree);

    return 0;
}