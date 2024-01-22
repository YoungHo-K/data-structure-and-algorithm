#include "graph_traversal.h"


void DFS(Vertex* vertex){
    Edge* edge = NULL;

    printf("%d ", vertex->data);

    vertex->visited = Visited;
    edge = vertex->adjacency_list;
    while(edge != NULL){
        if(edge->target != NULL && edge->target->visited == NotVisited)
            DFS(edge->target);
        
        edge = edge->next;
    }
}

void BFS(Vertex* vertex, LinkedQueue* queue){
    Edge* edge = NULL;

    printf("%d ", vertex->data);
    vertex->visited = Visited;

    enqueue(queue, createNode(vertex));

    while(!isEmpty(queue)){
        Node* popped = dequeue(queue);
        vertex = popped->data;
        edge = vertex->adjacency_list;

        while(edge != NULL){
            vertex = edge->target;

            if(vertex != NULL && vertex->visited == NotVisited){
                printf("%d ", vertex->data);
                vertex->visited = Visited;
                enqueue(queue, createNode(vertex));
            }

            edge = edge->next;
        }
    }
}