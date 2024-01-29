#include "graph.h"
#include "topological_sort.h"


int main(void){
    Node* sorted_list = NULL;
    Node* current_node = NULL;

    Graph* graph = createGraph();

    Vertex* A = createVertex('A');
    Vertex* B = createVertex('B');
    Vertex* C = createVertex('C');
    Vertex* D = createVertex('D');
    Vertex* E = createVertex('E');
    Vertex* F = createVertex('F');
    Vertex* G = createVertex('G');
    Vertex* H = createVertex('H');

    addVertex(graph, A);
    addVertex(graph, B);
    addVertex(graph, C);
    addVertex(graph, D);
    addVertex(graph, E);
    addVertex(graph, F);
    addVertex(graph, G);
    addVertex(graph, H);

    addEdge(A, createEdge(A, C, 0));
    addEdge(A, createEdge(A, D, 0));

    addEdge(B, createEdge(B, C, 0));
    addEdge(B, createEdge(B, E, 0));

    addEdge(C, createEdge(C, F, 0));

    addEdge(D, createEdge(D, F, 0));
    addEdge(D, createEdge(D, G, 0));

    addEdge(E, createEdge(E, G, 0));

    addEdge(F, createEdge(F, H, 0));

    addEdge(G, createEdge(G, H, 0));

    topologicalSort(graph->vertices, &sorted_list);

    printf("Topological Sort Result: ");

    current_node = sorted_list;
    while(current_node != NULL){
        printf("%C ", current_node->data->data);
        current_node = current_node->next_node;
    }
    printf("\n");

    destroyGraph(graph);

    return 0;
}