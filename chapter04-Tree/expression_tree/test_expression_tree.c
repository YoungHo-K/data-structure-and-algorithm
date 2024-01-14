#include "expression_tree.h"


int main(void){
    Node* root = NULL;

    char postfix_expression[20] = "71*52-/";
    buildExpressionTree(postfix_expression, &root);

    printf("Preorder...\n");
    preorderPrintTree(root);
    printf("\n\n");

    printf("Inorder...\n");
    inorderPrintTree(root);
    printf("\n\n");

    printf("Postorder...\n");
    postorderPrintTree(root);
    printf("\n\n");

    printf("Evaluation Result: %f\n", evaluate(root));

    destroyTree(root);

    return 0;
}