#include "priority_queue.h"


PriorityQueue* create(int initial_size){
    PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->capacity = initial_size;
    q->used_size = 0;
    q->nodes = (Node*)malloc(sizeof(Node) * q->capacity);

    return q;
}

void destroy(PriorityQueue* q){
    free(q->nodes);
    free(q);
}

void enqueue(PriorityQueue* q, Node node){
    int current_position = q->used_size;
    int parent_position = getParent(current_position);

    if(q->used_size == q->capacity){
        if(q->capacity == 0)
            q->capacity = 1;

        q->capacity *= 2;
        q->nodes = (Node*)realloc(q->nodes, sizeof(Node) * q->capacity);
    }

    q->nodes[current_position] = node;

    while(current_position > 0 && q->nodes[current_position].priority < q->nodes[parent_position].priority){
        swapNodes(q, current_position, parent_position);

        current_position = parent_position;
        parent_position = getParent(current_position);
    }

    q->used_size++;
}

void swapNodes(PriorityQueue* q, int index1, int index2){
    int copy_size = sizeof(Node);
    Node* temp = (Node*)malloc(copy_size);

    memcpy(temp, &q->nodes[index1], copy_size);
    memcpy(&q->nodes[index1], &q->nodes[index2], copy_size);
    memcpy(&q->nodes[index2], temp, copy_size);

    free(temp);
}

void dequeue(PriorityQueue* q, Node* root){
    int parent_position = 0;
    int left_position = 0;
    int right_position = 0;

    memcpy(root, &q->nodes[0], sizeof(Node));
    memset(&q->nodes[0], 0, sizeof(Node));

    q->used_size--;
    swapNodes(q, 0, q->used_size);

    left_position = getLeftChild(0);
    right_position = left_position + 1;

    while(1){
        int selected_child = 0;

        if(left_position >= q->used_size)
            break;

        if(right_position >= q->used_size)
            selected_child = left_position;
        else{
            if(q->nodes[left_position].priority > q->nodes[right_position].priority)
                selected_child = right_position;
            else
                selected_child = left_position;
        }

        if(q->nodes[selected_child].priority < q->nodes[parent_position].priority){
            swapNodes(q, parent_position, selected_child);
            parent_position = selected_child;
        }
        else
            break;

        left_position = getLeftChild(parent_position);
        right_position = left_position + 1;
    }

    if(q->used_size < (q->capacity / 2)){
        q->capacity /= 2;
        q->nodes = (Node*)realloc(q->nodes, sizeof(Node) * q->capacity);
    }
}

int getParent(int index){
    return (int)((index - 1) / 2);
}

int getLeftChild(int index){
    return (2 * index) + 1;
}

int isEmpty(PriorityQueue* q){
    return (q->used_size == 0);
}
