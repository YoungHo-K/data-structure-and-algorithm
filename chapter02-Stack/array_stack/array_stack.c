#include "array_stack.h"


void createStack(ArrayStack** stack, int capacity){
    (*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));    
    
    (*stack)->nodes = (Node*)malloc(sizeof(Node) * capacity);
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}


void destroyStack(ArrayStack* stack){
    free(stack->nodes);
    free(stack);
}

void push(ArrayStack* stack, ElementType data){
    stack->top++;
    stack->nodes[stack->top].data = data;
}

ElementType pop(ArrayStack* stack){
    int position = stack->top--;
    
    return stack->nodes[position].data;
}

ElementType top(ArrayStack* stack){
    return stack->nodes[stack->top].data;
}

int getSize(ArrayStack* stack){
    return stack->top + 1;
}

int isEmpty(ArrayStack* stack){
    return (stack->top == -1);
}

int isFull(ArrayStack* stack){
    return (stack->top + 1 == stack->capacity);
}