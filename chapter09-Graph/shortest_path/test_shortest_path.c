#include "graph.h"
#include "shortest_path.h"


int main(void){
    Graph* graph       = createGraph();
    Graph* prim_mst    = createGraph();

    Vertex* A = createVertex('A');
    Vertex* B = createVertex('B');
    Vertex* C = createVertex('C');
    Vertex* D = createVertex('D');
    Vertex* E = createVertex('E');
    Vertex* F = createVertex('F');
    Vertex* G = createVertex('G');
    Vertex* H = createVertex('H');
    Vertex* I = createVertex('I');

    addVertex(graph, A);
    addVertex(graph, B);
    addVertex(graph, C);
    addVertex(graph, D);
    addVertex(graph, E);
    addVertex(graph, F);
    addVertex(graph, G);
    addVertex(graph, H);
    addVertex(graph, I);

    addEdge(A, createEdge(A, E, 247));

    addEdge(B, createEdge(B, A, 35));
    addEdge(B, createEdge(B, C, 126));
    addEdge(B, createEdge(B, F, 150));

    addEdge(C, createEdge(C, D, 117));
    addEdge(C, createEdge(C, F, 162));
    addEdge(C, createEdge(C, G, 220));

    addEdge(E, createEdge(E, H, 98));

    addEdge(F, createEdge(F, E, 82));
    addEdge(F, createEdge(F, G, 154));
    addEdge(F, createEdge(F, H, 120));

    addEdge(G, createEdge(G, I, 106));

    dijkstra(graph, B, prim_mst);
    printGraph(prim_mst);

    destroyGraph(prim_mst);
    destroyGraph(graph);

    return 0;
}