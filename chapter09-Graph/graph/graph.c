#include "graph.h"


Graph* createGraph(){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertex_count = 0;

    return graph;
}

void destroyGraph(Graph* graph){
    while(graph->vertices != NULL){
        Vertex* vertices = graph->vertices->next;
        destroyVertex(graph->vertices);
        graph->vertices = vertices;
    }

    free(graph);
}

Vertex* createVertex(ElementType data){
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->data = data;
    vertex->next = NULL;
    vertex->adjacency_list = NULL;
    vertex->visited = NotVisited;
    vertex->index = -1;

    return vertex;
}

void destroyVertex(Vertex* vertex){
    while(vertex->adjacency_list != NULL){
        Edge* edge = vertex->adjacency_list->next;
        destroyEdge(vertex->adjacency_list);

        vertex->adjacency_list = edge;
    }

    free(vertex);
}

Edge* createEdge(Vertex* from, Vertex* target, int weight){
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->from = from;
    edge->target = target;
    edge->next = NULL;
    edge->weight = weight;

    return edge;
}

void destroyEdge(Edge* edge){
    free(edge);
}

void addVertex(Graph* graph, Vertex* vertex){
    Vertex* vertex_list = graph->vertices;

    if(vertex_list == NULL)
        graph->vertices = vertex;
    else{
        while(vertex_list->next != NULL)
            vertex_list = vertex_list->next;
        
        vertex_list->next = vertex;
    }

    vertex->index = graph->vertex_count++;
}

void addEdge(Vertex* vertex, Edge* edge){
    if(vertex->adjacency_list == NULL)
        vertex->adjacency_list = edge;
    else{
        Edge* adjacency_list = vertex->adjacency_list;
        while(adjacency_list->next != NULL)
            adjacency_list = adjacency_list->next;

        adjacency_list->next = edge;
    }
}

void printGraph(Graph* graph){
    Vertex* vertex = NULL;
    Edge* edge = NULL;

    if((vertex = graph->vertices) == NULL)
        return;
    
    while(vertex != NULL){
        printf("%c: ", vertex->data);

        if((edge = vertex->adjacency_list) == NULL){
            vertex = vertex->next;
            printf("\n");
            continue;
        }

        while(edge != NULL){
            printf("%c[%d] ", edge->target->data, edge->weight);
            edge = edge->next;
        }

        printf("\n");

        vertex = vertex->next;
    }

    printf("\n");
}