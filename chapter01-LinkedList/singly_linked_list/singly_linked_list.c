#include "singly_linked_list.h"


Node* CreateNode(ElementType data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next_node = NULL;

    return new_node;
}


void DestroyNode(Node* node){
    free(node);
}


void DestroyAllNodes(Node** head){
    Node* current = NULL;

    while((*head) != NULL){
        current = (*head)->next_node;
        DestroyNode(*head);
        *head = current;
    }
}

void AppendNode(Node** head, Node* new_node){
    if(*head == NULL){
        *head = new_node;
    }
    else{
        Node* tail = *head;
        while(tail->next_node != NULL){
            tail = tail->next_node;
        }
        
        tail->next_node = new_node;
    }
}


void InsertAfter(Node* current, Node* new_node){
    new_node->next_node = current->next_node;
    current->next_node = new_node;
}


void InsertBefore(Node** head, Node* current, Node* new_head){
    Node* node = *head;
    while(node != NULL && node->next_node != current){
        node = node->next_node;
    }

    if(node != NULL){
        new_head->next_node = current;
        node->next_node = new_head;
    }
}


void InsertNewHead(Node** head, Node* new_head){
    if(*head == NULL){
        *head = new_head;
    }
    else{
        new_head->next_node = *head;
        *head = new_head;
    }
}


void RemoveNode(Node** head, Node* node){
    if(*head == node){
        *head = node->next_node;
    }
    else{
        Node* current = *head;
        while(current != NULL && current->next_node != node){
            current = current->next_node;
        }

        if(current != NULL){
            current->next_node = node->next_node;
        }
    }
}


Node* GetNodeAt(Node* head, int location){
    Node* current = head;
    while(current != NULL && (--location) >= 0){
        current = current->next_node;
    }

    return current;
}


int GetNodeCount(Node* head){
    int count = 0;
    Node* current = head;

    while(current != NULL){
        current = current->next_node;
        count++;
    }

    return count;
}