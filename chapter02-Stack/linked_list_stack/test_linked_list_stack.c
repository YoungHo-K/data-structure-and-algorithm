#include "linked_list_stack.h"


int main(void){
    int i = 0;
    int count = 0;
    Node* popped;
    LinkedListStack* stack;

    createStack(&stack);

    push(stack, createNode("abc"));
    push(stack, createNode("def"));
    push(stack, createNode("efg"));
    push(stack, createNode("hij"));

    count = getSize(stack);
    printf("Size: %d, Top: %s\n\n", count, top(stack)->data);

    for(i = 0; i < count; i++){
        if(isEmpty(stack))
            break;
        
        popped = pop(stack);
        printf("Popped: %s, ", popped->data);
        
        destroyNode(popped);
        if(!isEmpty(stack))
            printf("Current Top: %s\n", top(stack)->data);
        else
            printf("Stack is empty.\n");
    }

    destroyStack(stack);

    return 0;
}