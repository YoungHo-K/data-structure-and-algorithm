#include "graph.h"
#include "graph_traversal.h"


int main(void){
    int mode = 0;
    Graph* graph = createGraph();

    Vertex* v1 = createVertex(1);
    Vertex* v2 = createVertex(2);
    Vertex* v3 = createVertex(3);
    Vertex* v4 = createVertex(4);
    Vertex* v5 = createVertex(5);
    Vertex* v6 = createVertex(6);
    Vertex* v7 = createVertex(7);

    addVertex(graph, v1);
    addVertex(graph, v2);
    addVertex(graph, v3);
    addVertex(graph, v4);
    addVertex(graph, v5);
    addVertex(graph, v6);
    addVertex(graph, v7);

    addEdge(v1, createEdge(v1, v2, 0));
    addEdge(v1, createEdge(v1, v3, 0));

    addEdge(v2, createEdge(v2, v4, 0));
    addEdge(v2, createEdge(v2, v5, 0));

    addEdge(v3, createEdge(v3, v4, 0));
    addEdge(v3, createEdge(v3, v6, 0));

    addEdge(v4, createEdge(v4, v5, 0));
    addEdge(v4, createEdge(v4, v7, 0));

    addEdge(v5, createEdge(v5, v7, 0));

    addEdge(v6, createEdge(v6, v7, 0));

    printf("Enter Traversal Model (0: DFS, 1: BFS) : ");
    scanf("%d", &mode);

    if(mode == 0)
        DFS(graph->vertices);
    else{
        LinkedQueue* queue = NULL;
        createQueue(&queue);

        BFS(v1, queue);

        destroyQueue(queue);
    }

    destroyGraph(graph);

    return 0;
}