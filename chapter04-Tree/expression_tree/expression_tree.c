#include "expression_tree.h"


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

    printf("(");
    inorderPrintTree(node->left);

    printf(" %c ", node->data);

    inorderPrintTree(node->right);
    printf(")");
}

void postorderPrintTree(Node* node){
    if(node == NULL)
        return;

    postorderPrintTree(node->left);
    postorderPrintTree(node->right);
    printf(" %c", node->data);
}


void buildExpressionTree(char* postfix_expression, Node** node){
    int length = strlen(postfix_expression);
    char token = postfix_expression[length - 1];
    postfix_expression[length - 1] = '\0';

    switch(token){
        case '+':
        case '-': 
        case '*':
        case '/':
            (*node) = createNode(token);
            buildExpressionTree(postfix_expression, &(*node)->right);
            buildExpressionTree(postfix_expression, &(*node)->left);
            break;
        default:
            (*node) = createNode(token);
            break;
    }

}

double evaluate(Node* tree){
    char temp[2];

    double left = 0;
    double right = 0;
    double result = 0;

    if(tree == NULL)
        return 0;
    
    switch(tree->data){
        case '+':
        case '-':
        case '*':
        case '/':
            left = evaluate(tree->left);
            right = evaluate(tree->right);

            if(tree->data == '+')
                result = left + right;

            else if(tree->data == '-')
                result = left - right;

            else if(tree->data == '*')
                result = left * right;

            else if(tree->data == '/')
                result = left / right;

            break;
        
        default:
            memset(temp, 0, sizeof(temp));
            temp[0] = tree->data;
            result = atof(temp);
            break;            
    }

    return result;
}