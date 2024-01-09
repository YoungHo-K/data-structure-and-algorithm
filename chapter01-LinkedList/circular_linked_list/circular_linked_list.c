#include "circular_linked_list.h"


Node* CreateNode(ElementType data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->prev_node = NULL;
    new_node->next_node = NULL;

    return new_node;
}


void DestroyNode(Node* node){
    free(node);
}


void AppendNode(Node** head, Node* new_node){
    if(*head == NULL){
        *head = new_node;
        (*head)->prev_node = *head;
        (*head)->next_node = *head;
    }
    else{
        Node* tail = (*head)->prev_node;

        (*head)->prev_node = new_node;
        tail->next_node = new_node;

        new_node->next_node = *head;
        new_node->prev_node = tail;
    }
}


Node* GetNodeAt(Node* head, int location){
    Node* current = head;
    while(current != NULL && (--location) >= 0){
        current = current->next_node;
    }

    return current;
}


void RemoveNode(Node** head, Node* node){
    if(*head == node){
        (*head)->next_node->prev_node = node->prev_node;
        (*head)->prev_node->next_node = node->next_node;
        *head = node->next_node;
    }
    else{
        node->next_node->prev_node = node->prev_node;
        node->prev_node->next_node = node->next_node;
    }

    node->prev_node = NULL;
    node->next_node = NULL;
}


void InsertAfter(Node* current, Node* new_node){
    new_node->prev_node = current;
    new_node->next_node = current->next_node;

    if(current->next_node != NULL){
        current->next_node->prev_node = new_node;
        current->next_node = new_node;
    }
}


int GetNodeCount(Node* head){
    unsigned int count = 0;
    Node*      current = head;

    while(current != NULL){
        current = current->next_node;
        count++;

        if(current == head)
            break;
    }

    return count;
}


void PrintNode(Node* node){
    if(node->prev_node == NULL){
        printf("Prev: NULL");
    }
    else{
        printf("Prev: %d", node->prev_node->data);
    }

    printf("Current: %d", node->data);

    if(node->next_node == NULL)
        printf("Next: NULL\n");
    else
        printf("Next:  %d\n", node->next_node->data);
}


void PrintReverse(Node* head){
    Node* current = head->prev_node;

    while(current != head){
        printf("Data: %d\n", current->data);
        current = current->prev_node;

        if(current == head)
            printf("Data: %d\n", current->data);
    }    
}