#include "heap.h"


Heap* create(int initial_size){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = initial_size;
    heap->used_size = 0;
    heap->nodes = (Node*)malloc(sizeof(Node) * heap->capacity);

    printf("size: %d\n", sizeof(Node));

    return heap;
}

void destroy(Heap* heap){
    free(heap->nodes);
    free(heap);
}

void insert(Heap* heap, ElementType data){
    int current_position = heap->used_size;
    int parent_position = getParent(current_position);

    if(heap->used_size == heap->capacity){
        heap->capacity *= 2;
        heap->nodes = (Node*)realloc(heap->nodes, sizeof(Node) * heap->capacity);
    }

    heap->nodes[current_position].data = data;

    while(current_position > 0 && heap->nodes[current_position].data < heap->nodes[parent_position].data){
        swapNodes(heap, current_position, parent_position);

        current_position = parent_position;
        parent_position = getParent(current_position);
    }

    heap->used_size++;
}

void swapNodes(Heap* heap, int index1, int index2){
    int copy_size = sizeof(Node);
    Node* temp = (Node*)malloc(copy_size);

    memcpy(temp, &heap->nodes[index1], copy_size);
    memcpy(&heap->nodes[index1], &heap->nodes[index2], copy_size);
    memcpy(&heap->nodes[index2], temp, copy_size);

    free(temp);
}

void deleteMin(Heap* heap, Node* root){
    int parent_position = 0;
    int left_position = 0;
    int right_position = 0;

    memcpy(root, &heap->nodes[0], sizeof(Node));
    memset(&heap->nodes[0], 0, sizeof(Node));

    heap->used_size--;
    swapNodes(heap, 0, heap->used_size);

    left_position = getLeftChild(0);
    right_position = left_position + 1;

    while(1){
        int selected_child = 0;
        if(left_position >= heap->used_size)
            break;
        
        if(right_position >= heap->used_size)
            selected_child = left_position;
        else{
            if(heap->nodes[left_position].data > heap->nodes[right_position].data)
                selected_child = right_position;
            else
                selected_child = left_position;
        }

        if(heap->nodes[selected_child].data < heap->nodes[parent_position].data){
            swapNodes(heap, parent_position, selected_child);
            parent_position = selected_child;
        }
        else
            break;

        left_position = getLeftChild(parent_position);
        right_position = left_position + 1;
    }

    if(heap->used_size < (heap->capacity / 2)){
        heap->capacity /= 2;
        heap->nodes = (Node*)realloc(heap->nodes, sizeof(Node) * heap->capacity);
    }
}

int getParent(int index){
    return (int)((index - 1) / 2);
}

int getLeftChild(int index){
    return (2 * index) + 1;
}

void printNodes(Heap* heap){
    int i = 0;
    for(i = 0; i < heap->used_size; i++){
        printf("%d ", heap->nodes[i].data);
    }
    printf("\n");
}
