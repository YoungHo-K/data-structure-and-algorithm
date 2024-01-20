#include "heap.h"


int main(void){
    Heap* heap = create(3);

    Node min_node;

    insert(heap, 12);
    insert(heap, 87);
    insert(heap, 111);
    insert(heap, 34);
    insert(heap, 16);
    insert(heap, 75);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    deleteMin(heap, &min_node);
    printNodes(heap);

    return 0;
}