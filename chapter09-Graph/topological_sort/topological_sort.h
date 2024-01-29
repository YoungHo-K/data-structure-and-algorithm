#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "graph.h"
#include "singly_linked_list.h"

void topologicalSort(Vertex* vertex, Node** list);
void topologicalSortDFS(Vertex* vertex, Node** list);

#endif
