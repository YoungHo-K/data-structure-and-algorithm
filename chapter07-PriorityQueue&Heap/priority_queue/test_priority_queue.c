#include "priority_queue.h"


void printNode(Node* node){
    printf("Job: %s (Priority: %d)\n", node->data, node->priority);
}

int main(void){
    PriorityQueue* q = create(3);
    Node popped;

    Node nodes[7] = {
        {34, (void*)"코딩"},
        {12, (void*)"고객미팅"},
        {87, (void*)"커피타기"},
        {45, (void*)"문서작성"},
        {35, (void*)"디버깅"},
        {66, (void*)"이닦기"}
    };

    enqueue(q, nodes[0]);
    enqueue(q, nodes[1]);
    enqueue(q, nodes[2]);
    enqueue(q, nodes[3]);
    enqueue(q, nodes[4]);
    enqueue(q, nodes[5]);

    printf("큐에 남아있는 작업의 수: %d\n", q->used_size);

    while(!isEmpty(q)){
        dequeue(q, &popped);
        printNode(&popped);
    }

    return 0;
}