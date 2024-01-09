#include "array_stack.h"

int main(void){
    int i = 0;
    ArrayStack* stack = NULL;

    createStack(&stack, 10);

    push(stack, 3);
    push(stack, 37);
    push(stack, 11);
    push(stack, 12);
    printf("Capacity: %d, Size: %d, Top: %d\n\n", stack->capacity, getSize(stack), top(stack));

    for(i = 0; i < 4; i++){
        if(isEmpty(stack))
            break;

        printf("Popped: %d, ", pop(stack));

        if(!isEmpty(stack))
            printf("Current Top: %d\n", top(stack));
        else
            printf("Stack is empty.\n");
    }

    destroyStack(stack);

    return 0;
}