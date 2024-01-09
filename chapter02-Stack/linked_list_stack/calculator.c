#include "calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int isNumber(char cipher){
    int i = 0;
    int array_length = sizeof(NUMBER);

    for(i = 0; i < array_length; i++){
        if(cipher == NUMBER[i])
            return 1;
    }

    return 0;
}

unsigned int getNextToken(char* expression, char* token, int* TYPE){
    unsigned int i = 0;

    for(i = 0; 0 != expression[i]; i++){
        token[i] = expression[i];

        if(isNumber(expression[i]) == 1){
            *TYPE = OPERAND;
            if(isNumber(expression[i + 1]) != 1)
                break;
        }
        else{
            *TYPE = expression[i];
            break;
        }
    }

    token[++i] = '\0';

    return i;
}

int getPriority(char operator, int in_stack){
    int priority = -1;

    switch(operator){
        case LEFT_PARENTHESIS:
            if(in_stack)
                priority = 3;
            else
                priority = 0;
            
            break;
        
        case MULTIPLY:
        case DIVIDE:
            priority = 1;
            break;

        case PLUS:
        case MINUS:
            priority = 2;
            break;
    }

    return priority;
}

int isPrior(char operator_in_stack, char operator_in_token){
    return ( getPriority(operator_in_stack, 1) > getPriority(operator_in_token, 0) );
}

void getPostfix(char* infix_expression, char* postfix_expression){
    LinkedListStack* stack;

    char token[32];
    int type = -1;
    unsigned int position = 0;
    unsigned int length = strlen(infix_expression);

    createStack(&stack);

    while(position < length){
        position += getNextToken(&infix_expression[position], token, &type);

        if(type == OPERAND){
            strcat(postfix_expression, token);
            strcat(postfix_expression, " ");
        }
        else if(type == RIGHT_PARENTHESIS){
            while(!isEmpty(stack)){
                Node* popped = pop(stack);

                if(popped->data[0] == LEFT_PARENTHESIS){
                    destroyNode(popped);
                    break;
                }
                else{
                    strcat(postfix_expression, popped->data);
                    destroyNode(popped);
                }
            }
        }
        else{
            while(!isEmpty(stack) && !isPrior(top(stack)->data[0], token[0])){
                Node* popped = pop(stack);

                if(popped->data[0] != LEFT_PARENTHESIS)
                    strcat(postfix_expression, popped->data);
                
                destroyNode(popped);
            }

            push(stack, createNode(token));
        }
    }

    while(!isEmpty(stack)){
        Node* popped = pop(stack);

        if(popped->data[0] != LEFT_PARENTHESIS)
            strcat(postfix_expression, popped->data);
        
        destroyNode(popped);
    }

    destroyStack(stack);
}

double calculate(char* postfix_expression){
    LinkedListStack* stack;
    Node* result_node;

    double result;
    char token[32];
    int type = -1;
    unsigned int read = 0;
    unsigned int length = strlen(postfix_expression);

    createStack(&stack);

    while(read < length){
        read += getNextToken(&postfix_expression[read], token, &type);

        if(type == SPACE)
            continue;
        
        if(type == OPERAND){
            Node* new_node = createNode(token);
            push(stack, new_node);
        }
        else{
            char result_string[32];
            double operator1, operator2, temp_result;
            Node* operator_node;

            operator_node = pop(stack);
            operator2 = atof(operator_node->data);
            destroyNode(operator_node);

            operator_node = pop(stack);
            operator1 = atof(operator_node->data);
            destroyNode(operator_node);

            switch(type){
                case PLUS:     temp_result = operator1 + operator2; break;
                case MINUS:    temp_result = operator1 - operator2; break;
                case MULTIPLY: temp_result = operator1 * operator2; break;
                case DIVIDE:   temp_result = operator1 / operator2; break;
            }

            gcvt(temp_result, 10, result_string);
            push(stack, createNode(result_string));
        }
    }

    result_node = pop(stack);
    result = atof(result_node->data);

    destroyNode(result_node);
    destroyStack(stack);

    return result;
}