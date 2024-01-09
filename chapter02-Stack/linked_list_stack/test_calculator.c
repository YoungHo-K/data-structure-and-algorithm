#include <stdio.h>
#include <string.h>
#include "calculator.h"

int main(void){
    char infix_expression[100];
    char postfix_expression[100];

    double result = 0.0;

    memset(infix_expression, 0, sizeof(infix_expression));
    memset(postfix_expression, 0, sizeof(postfix_expression));

    printf("Enter Infix Expression:");
    scanf("%s", infix_expression);

    getPostfix(infix_expression, postfix_expression);

    printf("Infix: %s\nPostfix: %s\n", infix_expression, postfix_expression);

    result = calculate(postfix_expression);
    printf("Calculation Result: %f\n", result);

    return 0;
}