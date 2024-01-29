#include "graph.h"
#include "minimum_spanning_tree.h"


int main(void){
    Graph* graph = createGraph();
    Graph* prim_mst = createGraph();
    Graph* kruscal_mst = createGraph();

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

    addEdge(A, createEdge(A, B, 35));
    addEdge(A, createEdge(A, E, 247));

    addEdge(B, createEdge(B, A, 35));
    addEdge(B, createEdge(B, C, 126));
    addEdge(B, createEdge(B, F, 150));

    addEdge(C, createEdge(C, B, 126));
    addEdge(C, createEdge(C, D, 117));
    addEdge(C, createEdge(C, F, 162));
    addEdge(C, createEdge(C, G, 220));

    addEdge(D, createEdge(D, C, 117));

    addEdge(E, createEdge(E, A, 247));
    addEdge(E, createEdge(E, F, 82));
    addEdge(E, createEdge(E, H, 98));

    addEdge(F, createEdge(F, B, 150));
    addEdge(F, createEdge(F, C, 162));
    addEdge(F, createEdge(F, E, 82));
    addEdge(F, createEdge(F, G, 154));
    addEdge(F, createEdge(F, H, 120));

    addEdge(G, createEdge(G, C, 220));
    addEdge(G, createEdge(G, F, 154));
    addEdge(G, createEdge(G, I, 106));

    addEdge(H, createEdge(H, E, 98));
    addEdge(H, createEdge(H, F, 120));

    addEdge(I, createEdge(I, G, 106));

    printf("Prim's Algorithm\n");
    prim(graph, B, prim_mst);
    printGraph(prim_mst);

    printf("Kruscal's Algorithm\n");
    kruscal(graph, kruscal_mst);
    printGraph(kruscal_mst);

    destroyGraph(prim_mst);
    destroyGraph(kruscal_mst);
    destroyGraph(graph);

    return 0;
}