#include "huffman.h"
#include <string.h>

int main(void){
    char* source = "This Is Algorithms.";
    char* decoded = "";

    HuffmanNode* tree = NULL;
    BitBuffer encoded = {NULL, 0};
    HuffmanCode code_table[MAX_CHAR];

    memset(&code_table, 0, sizeof(HuffmanCode) * MAX_CHAR);

    huffman_encode(&tree, (UCHAR*)source, &encoded, code_table);

    printf("Original Size: %lu Encoded Size: %d\n",
                (strlen(source) + 1) * sizeof(char) * 8, encoded.size);
    
    decoded = (char*)malloc(sizeof(char) * (strlen(source) + 1));
    huffman_decode(tree, &encoded, (UCHAR*)decoded);

    printf("Original : %s\n", source);
    printf("Encoded  : ");

    huffman_printBinary(&encoded);

    printf("\n");

    printf("Decoded: %s\n", decoded);

    huffman_destroyTree(tree);
    free(decoded);

    return 0;
}