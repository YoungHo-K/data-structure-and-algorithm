#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode {Visited, NotVisited};

typedef int ElementType;

typedef struct tagVertex{
    ElementType data;
    int visited;
    int index;

    struct tagVertex* next;
    struct tagEdge* adjacency_list;
} Vertex;

typedef struct tagEdge{
    int weight;
    struct tagEdge* next;
    Vertex* from;
    Vertex* target;
} Edge;

typedef struct tagGraph{
    Vertex* vertices;
    int vertex_count;
} Graph;

Graph*  createGraph();
void    destroyGraph(Graph* graph);
Vertex* createVertex(ElementType data);
void    destroyVertex(Vertex* vertex);
Edge*   createEdge(Vertex* from ,Vertex* target, int weight);
void    destroyEdge(Edge* edge);
void    addVertex(Graph* graph, Vertex* vertex);
void    addEdge(Vertex* vertex, Edge* edge);
void    printGraph(Graph* graph);

#endif