#include "doubly_linked_list.h"

int main(void){
    int   i        = 0;
    int   count    = 0;
    Node* list     = NULL;
    Node* new_node = NULL;
    Node* current  = NULL;

    for(i = 0; i < 5; i++){
        new_node = CreateNode(i);
        AppendNode(&list, new_node);
    }

    count = GetNodeCount(list);
    for(i = 0; i < count; i++){
        current = GetNodeAt(list, i);
        printf("List[%d]: %d\n", i, current->data);
    }

    printf("\nInserting 3000 After [2].\n");

    current = GetNodeAt(list, 2);
    new_node = CreateNode(3000);
    InsertAfter(current, new_node);

    count = GetNodeCount(list);
    for(i = 0; i < count; i++){
        current = GetNodeAt(list, i);
        printf("List[%d]: %d\n", i, current->data);        
    }

    printf("\nReverse Printing.\n");
    PrintReverse(list);

    printf("\nDestroying List.\n");

    count = GetNodeCount(list);
    for(i = 0; i < count; i++){
        current = GetNodeAt(list, 0);
        if(current != NULL){
            RemoveNode(&list, current);
            DestroyNode(current);
        }
    }

    return 0;
}