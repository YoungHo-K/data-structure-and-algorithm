#include "linked_queue.h"

int main(void){
    Node* popped;
    LinkedQueue* queue;

    createQueue(&queue);

    enqueue(queue, createNode("abc"));
    enqueue(queue, createNode("def"));
    enqueue(queue, createNode("efg"));
    enqueue(queue, createNode("hij"));
    
    printf("Queue Size: %d\n", queue->count);

    while(isEmpty(queue) == 0){
        popped = dequeue(queue);
        printf("Dequeue: %s\n", popped->data);

        destroyNode(popped);
    }

    destroyQueue(queue);
    
    return 0;
}