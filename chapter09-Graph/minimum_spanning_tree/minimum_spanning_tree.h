#ifndef MST_H
#define MST_H

#include "graph.h"
#include "priority_queue.h"
#include "disjoint_set.h"

#define MAX_WEIGHT 36267

void prim(Graph* graph, Vertex* start_vertex, Graph* mst);
void kruscal(Graph* graph, Graph* mst);

#endif

