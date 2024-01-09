#include "linked_list_stack.h"


void createStack(LinkedListStack** stack){
    (*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*stack)->list = NULL;
    (*stack)->top = NULL;
}

void destroyStack(LinkedListStack* stack){
    while(!isEmpty(stack)){
        Node* popped = pop(stack);
        destroyNode(popped);
    }

    free(stack);
}

Node* createNode(char* new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(strlen(new_data) + 1);

    strcpy(new_node->data, new_data);

    new_node->next_node = NULL;

    return new_node;
}

void destroyNode(Node* node){
    free(node->data);
    free(node);
}

void push(LinkedListStack* stack, Node* new_node){
    if(stack->list == NULL)
        stack->list = new_node;
    else
        stack->top->next_node = new_node;

    stack->top = new_node;
}

Node* pop(LinkedListStack* stack){
    Node* top_node = stack->top;

    if(stack->list == stack->top){
        stack->list = NULL;
        stack->top = NULL;
    }
    else{
        Node* current_node = stack->list;
        while(current_node != NULL && current_node->next_node != stack->top){
            current_node = current_node->next_node;
        }

        stack->top = current_node;
        stack->top->next_node = NULL;
    }

    return top_node;
}

Node* top(LinkedListStack* stack){
    return stack->top;
}

int getSize(LinkedListStack* stack){
    int size = 0;
    Node* current = stack->list;

    while(current != NULL){
        current = current->next_node;
        size++;
    }

    return size;
}

int isEmpty(LinkedListStack* stack){
    return (stack->list == NULL);
}
