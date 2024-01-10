#include "linked_queue.h"

void createQueue(LinkedQueue** queue){
    (*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->count = 0;
}


void destroyQueue(LinkedQueue* queue){
    while(!isEmpty(queue)){
        Node* popped = dequeue(queue);
        destroyNode(popped);
    }

    free(queue);
}

Node* createNode(char* data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = (char*)malloc(strlen(data) + 1);

    strcpy(node->data, data);

    node->next_node = NULL;

    return node;
}

void destroyNode(Node* node){
    free(node->data);
    free(node);
}

void enqueue(LinkedQueue* queue, Node* node){
    if(queue->front == NULL){
        queue->front = node;
        queue->rear = node;
    }
    else{
        queue->rear->next_node = node;
        queue->rear = node;
    }

    queue->count++;     
}

Node* dequeue(LinkedQueue* queue){
    Node* front = queue->front;

    if(queue->front->next_node == NULL){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = queue->front->next_node;
    }
    queue->count--;

    return front;
}

int isEmpty(LinkedQueue* queue){
    return queue->front == NULL;
}