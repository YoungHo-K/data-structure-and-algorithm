#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "graph.h"
#include "priority_queue.h"

#define MAX_WEIGHT 36267

void dijkstra(Graph* graph, Vertex* vertex, Graph* mst);

#endif