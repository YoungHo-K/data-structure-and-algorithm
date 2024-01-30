#include "shortest_path.h"


void dijkstra(Graph* graph, Vertex* start_vertex, Graph* shortest_path){
    int i = 0;

    Node           start_node = {0, start_vertex};
    PriorityQueue* pq         = create(10);

    Vertex* current_vertex = NULL;
    Edge*   current_edge   = NULL;

    int*     weights                = (int*)malloc(sizeof(int) * graph->vertex_count);
    Vertex** shortest_path_vertices = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);
    Vertex** fringes                = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);
    Vertex** precedences            = (Vertex**)malloc(sizeof(Vertex*) * graph->vertex_count);

    current_vertex = graph->vertices;
    while(current_vertex != NULL){
        Vertex* new_vertex = createVertex(current_vertex->data);
        addVertex(shortest_path, new_vertex);

        fringes[i]                = NULL;
        precedences[i]            = NULL;
        shortest_path_vertices[i] = new_vertex;
        weights[i]                = MAX_WEIGHT;
        current_vertex            = current_vertex->next;
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
            
            if(fringes[target_vertex->index] == NULL && weights[current_vertex->index] + current_edge->weight < weights[target_vertex->index]){
                Node new_node = {current_edge->weight, target_vertex};
                enqueue(pq, new_node);

                precedences[target_vertex->index] = current_edge->from;
                weights[target_vertex->index] = weights[current_vertex->index] + current_edge->weight;
            }

            current_edge = current_edge->next;
        }
    }

    for(i = 0; i < graph->vertex_count; i++){
        int from_index, to_index;

        if(precedences[i] == NULL)
            continue;
        
        from_index = precedences[i]->index;
        to_index   = i;

        addEdge(shortest_path_vertices[from_index],
                createEdge(shortest_path_vertices[from_index],
                           shortest_path_vertices[to_index],
                           weights[i]));
    }

    free(fringes);
    free(precedences);
    free(shortest_path_vertices);
    free(weights);

    destroy(pq);
}