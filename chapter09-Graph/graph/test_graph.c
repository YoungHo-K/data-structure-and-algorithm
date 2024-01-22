#include "graph.h"


int main(void){
    Graph* graph = createGraph();

    Vertex* v1 = createVertex('1');
    Vertex* v2 = createVertex('2');
    Vertex* v3 = createVertex('3');
    Vertex* v4 = createVertex('4');
    Vertex* v5 = createVertex('5');

    addVertex(graph, v1);
    addVertex(graph, v2);
    addVertex(graph, v3);
    addVertex(graph, v4);
    addVertex(graph, v5);

    addEdge(v1, createEdge(v1, v2, 0));
    addEdge(v1, createEdge(v1, v3, 0));
    addEdge(v1, createEdge(v1, v4, 0));
    addEdge(v1, createEdge(v1, v5, 0));

    addEdge(v2, createEdge(v2, v1, 0));
    addEdge(v2, createEdge(v2, v3, 0));
    addEdge(v2, createEdge(v2, v5, 0));

    addEdge(v3, createEdge(v3, v1, 0));
    addEdge(v3, createEdge(v3, v2, 0));

    addEdge(v4, createEdge(v4, v1, 0));
    addEdge(v4, createEdge(v4, v5, 0));

    addEdge(v5, createEdge(v5, v1, 0));
    addEdge(v5, createEdge(v5, v2, 0));
    addEdge(v5, createEdge(v5, v4, 0));

    printGraph(graph);

    destroyGraph(graph);

    return 0;
}