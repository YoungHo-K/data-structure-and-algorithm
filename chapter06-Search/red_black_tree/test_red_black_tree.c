#include "red_black_tree.h"

Node* Nil;

int main(void){
    Node* tree = NULL;
    Node* node = NULL;

    Nil = createNode(0);
    Nil->color = BLACK;

    while(1){
        int cmd = 0;
        int param = 0;
        char buffer[10];

        printf("Enter command number :\n");
        printf("(1) Create a node, (2) Remov a node, (3) Search a node\n");
        printf("(4) Display tree, (5) quit\n");
        printf("command number:");

        fgets(buffer, sizeof(buffer) - 1, stdin);
        sscanf(buffer, "%d", &cmd);

        if(cmd < 1 || cmd > 5){
            printf("Invalid command number.\n");
            continue;
        }
        else if(cmd == 4){
            printTree(tree, 0, 0);
            printf("\n");
            continue;
        }
        else if(cmd == 5){
            break;
        }

        printf("Enter paramter (1-200):\n");
        
        fgets(buffer, sizeof(buffer) - 1, stdin);
        sscanf(buffer, "%d", &param);

        if(param < 1 || param > 200){
            printf("Invalid parameter.%d\n", param);
            continue;
        }

        switch(cmd){
            case 1:
                insertNode(&tree, createNode(param));
                break;

            case 2:
                node = removeNode(&tree, param);
                if(node == NULL)
                    printf("Not found node to delete:%d\n", param);
                else
                    destroyNode(node);
                
                break;
            
            case 3:
                node = searchNode(tree, param);
                if(node == NULL)
                    printf("Not found node:%d\n", param);
                else
                    printf("Found node: %d(color:%s)\n", node->data, (node->color == RED)?"RED":"BLACK");
                
                break;            
        }
        
        printf("\n");
    }

    destroyTree(tree);
    return 0;
}