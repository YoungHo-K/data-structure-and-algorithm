#include "minimum_spanning_tree.h"


void prim(Graph* graph, Vertex* start_vertex, Graph* mst){
    int i = 0;

    Node           start_node = {0, start_vertex};
    PriorityQueue* pq         = create(10);

    Vertex* current_vertex = NULL;
    Edge* current_edge     = NULL;

    int*    weights      = (int*)malloc(sizeof(int) * graph->vertex_count);
    Vertex** mstVertices = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);
    Vertex** fringes     = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);
    Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);

    current_vertex = graph->vertices;
    while(current_vertex != NULL){
        Vertex* new_vertex = createVertex(current_vertex->data);
        addVertex(mst, new_vertex);

        fringes[i]     = NULL;
        precedences[i] = NULL;
        mstVertices[i] = new_vertex;
        weights[i]     = MAX_WEIGHT;
        current_vertex = current_vertex->next;
        i++;
    }

    enqueue(pq, start_node);
    weights[start_vertex->index] = 0;

    while(!isEmpty(pq)){
        Node popped;

        dequeue(pq, &popped);
        current_vertex = (Vertex*)popped.data;

        fringes[current_vertex->index] = current_vertex;
        
        current_edge = current_vertex->adjacency_list;
        while(current_edge != NULL){
            Vertex* target_vertex = current_edge->target;
            if(fringes[target_vertex->index] == NULL && current_edge->weight < weights[target_vertex->index]){
                Node new_node = {current_edge->weight, target_vertex};
                enqueue(pq, new_node);

                precedences[target_vertex->index] = current_edge->from;
                weights[target_vertex->index] = current_edge->weight;
            }

            current_edge = current_edge->next;
        }
    }

    for(i = 0; i < graph->vertex_count; i++){
        int from_index, to_index;

        if(precedences[i] == NULL)
            continue;
        
        from_index = precedences[i]->index;
        to_index = i;

        addEdge(mstVertices[from_index], createEdge(mstVertices[from_index], mstVertices[to_index], weights[i]));
        addEdge(mstVertices[to_index], createEdge(mstVertices[to_index], mstVertices[from_index], weights[i]));
    }

    free(fringes);
    free(precedences);
    free(mstVertices);
    free(weights);

    destroy(pq);
}

void kruscal(Graph* graph, Graph* mst){
    int i;

    Vertex*        current_vertex = NULL;
    Vertex**       mstVertices    = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);
    DisjointSet**  vertex_set     = (DisjointSet**)malloc(sizeof(DisjointSet*) * graph->vertex_count);
    PriorityQueue* pq             = create(10);

    i = 0;
    current_vertex = graph->vertices;
    while(current_vertex != NULL){
        Edge* current_edge;

        vertex_set[i] = makeSet(current_vertex);
        mstVertices[i] = createVertex(current_vertex->data);
        addVertex(mst, mstVertices[i]);

        current_edge = current_vertex->adjacency_list;
        while(current_edge != NULL){
            Node new_node = {current_edge->weight, current_edge};
            enqueue(pq, new_node);

            current_edge = current_edge->next;
        }

        current_vertex = current_vertex->next;
        i++;
    }

    while(!isEmpty(pq)){
        Edge* current_edge;
        int   from_index;
        int   to_index;
        Node  popped;

        dequeue(pq, &popped);
        current_edge = (Edge*)popped.data;

        printf("%c - %c : %d\n", current_edge->from->data, current_edge->target->data, current_edge->weight);

        from_index = current_edge->from->index;
        to_index = current_edge->target->index;

        if(findSet(vertex_set[from_index]) != findSet(vertex_set[to_index])){
            addEdge(mstVertices[from_index], createEdge(mstVertices[from_index], mstVertices[to_index], current_edge->weight));
            addEdge(mstVertices[to_index], createEdge(mstVertices[to_index], mstVertices[from_index], current_edge->weight));

            unionSet(vertex_set[from_index], vertex_set[to_index]);
        }
    }

    for(i = 0; i < graph->vertex_count; i++)
        destroySet(vertex_set[i]);

    free(vertex_set);
    free(mstVertices);

}