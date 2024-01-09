#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "linked_list_stack.h"

typedef enum {
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
} SYMBOL;

int          isNumber(char cipher);
unsigned int getNextToken(char* expression, char* token, int* TYPE);
int          getPriority(char operator, int in_stack);
int          isPrior(char operator1, char operator2);
void         getPostfix(char* infix_expression, char* postfix_expression);
double       calculate(char* postfix_expression);

#endif