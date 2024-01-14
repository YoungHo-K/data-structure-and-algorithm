#include "disjoint_set.h"


void unionSet(DisjointSet* set1, DisjointSet* set2){
    set1 = findSet(set1);
    set2 = findSet(set2);
    set2->parent = set1;
}

DisjointSet* findSet(DisjointSet* set){
    while(set->parent != NULL){
        set = set->parent;
    }

    return set;
}

DisjointSet* makeSet(void* data){
    DisjointSet* set = (DisjointSet*)malloc(sizeof(DisjointSet));
    set->parent = NULL;
    set->data = data;

    return set;
}

void destroySet(DisjointSet* set){
    free(set);
}