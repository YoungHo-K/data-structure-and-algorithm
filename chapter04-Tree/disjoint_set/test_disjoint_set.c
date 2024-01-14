#include "disjoint_set.h"


int main(void){
    int a = 1, b = 2, c = 3, d = 4;

    DisjointSet* set1 = makeSet(&a);
    DisjointSet* set2 = makeSet(&b);
    DisjointSet* set3 = makeSet(&c);
    DisjointSet* set4 = makeSet(&d);

    printf("Set1 == Set2: %d\n", findSet(set1) == findSet(set2));

    unionSet(set1, set3);
    printf("Set1 == Set3: %d\n", findSet(set1) == findSet(set3));

    unionSet(set3, set4);
    printf("Set3 == Set4: %d\n", findSet(set3) == findSet(set4));

    return 0;
}