#include "topological_sort.h"


void topologicalSort(Vertex* vertex, Node** list){
    while(vertex != NULL && vertex->visited == NotVisited){
        topologicalSortDFS(vertex, list);
        vertex = vertex->next;
    }
}

void topologicalSortDFS(Vertex* vertex, Node** list){
    Node* head = NULL;
    Edge* edge = NULL;

    vertex->visited = Visited;
    edge = vertex->adjacency_list;
    while(edge != NULL){
        if(edge->target != NULL && edge->target->visited == NotVisited)
            topologicalSortDFS(edge->target, list);
        
        edge = edge->next;
    }

    printf("%c\n", vertex->data);

    head = CreateNode(vertex);
    InsertNewHead(list, head);
}