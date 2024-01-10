#include "circular_queue.h"

int main(void){
    int i;
    CircularQueue* queue;

    createQueue(&queue, 10);

    for(i = 1; i < 5; i++){
        enqueue(queue, i);
    }

    for(i = 1; i < 3; i++){
        printf("Dequeue: %d, ", dequeue(queue));
        printf("Front: %d, Rear: %d\n", queue->front, queue->rear);
    }

    i = 100;
    while(isFull(queue) == 0){
        enqueue(queue, i++);
    }

    printf("Capacity: %d, Size: %d\n\n", queue->capacity, getSize(queue));

    while(isEmpty(queue) == 0){
        printf("Dequeue: %d, ", dequeue(queue));
        printf("Front: %d, Rear: %d\n", queue->front, queue->rear);
    }

    destroyQueue(queue);

    return 0;
}