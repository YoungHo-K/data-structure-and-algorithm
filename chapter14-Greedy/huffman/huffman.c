#include "huffman.h"

HuffmanNode* huffman_createNode(SymbolInfo data){
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
}

void huffman_destroyNode(HuffmanNode* node){
    free(node);
}

void huffman_destroyTree(HuffmanNode* node){
    if(node == NULL)
        return;

    huffman_destroyTree(node->left);
    huffman_destroyTree(node->right);
    huffman_destroyNode(node);
}

void huffman_addBit(BitBuffer* buffer, char bit){
    UCHAR mask = 0x80;

    if(buffer->size % 8 == 0){
        buffer->buffer = realloc(buffer->buffer, sizeof(UCHAR) * ((buffer->size / 8) + 1));
        buffer->buffer[buffer->size / 8] = 0x00;
    }

    mask >>= buffer->size % 8;

    if(bit == 1)
        buffer->buffer[buffer->size / 8] |= mask;
    else
        buffer->buffer[buffer->size / 8] &= -mask;

    buffer->size++;
}

void huffman_buildCodeTable(HuffmanNode* tree, HuffmanCode code_table[MAX_CHAR], UCHAR code[MAX_BIT], int size){
    if(tree == NULL)
        return;

    if(tree->left != NULL){
        code[size] = 0;
        huffman_buildCodeTable(tree->left, code_table, code, size + 1);
    }

    if(tree->right != NULL){
        code[size] = 1;
        huffman_buildCodeTable(tree->right, code_table, code, size + 1);
    }

    if(tree->left == NULL && tree->right == NULL){
        int i;

        for(i = 0; i < size; i++)
            code_table[tree->data.symbol].code[i] = code[i];
        
        code_table[tree->data.symbol].size = size;
    }
}

void huffman_buildPrefixTree(HuffmanNode** tree, SymbolInfo symbol_info_table[MAX_CHAR]){
    int i = 0;
    Node result;
    PriorityQueue* pq = create(0);

    for(i = 0; i < MAX_CHAR; i++){
        if(symbol_info_table[i].frequency > 0){
            HuffmanNode* bit_node = huffman_createNode(symbol_info_table[i]);
            
            Node node;
            node.priority = symbol_info_table[i].frequency;
            node.data = bit_node;

            enqueue(pq, node);
        }
    }

    while(pq->used_size > 1){
        SymbolInfo data = {0, 0};
        HuffmanNode* bit_node = huffman_createNode(data);
        HuffmanNode* left;
        HuffmanNode* right;

        Node q_left;
        Node q_right;
        Node q_node;

        dequeue(pq, &q_left);
        dequeue(pq, &q_right);

        left = (HuffmanNode*)q_left.data;
        right = (HuffmanNode*)q_right.data;

        bit_node->data.symbol = 0;
        bit_node->data.frequency = left->data.frequency + right->data.frequency;

        bit_node->left = left;
        bit_node->right = right;

        q_node.priority = bit_node->data.frequency;
        q_node.data = bit_node;

        enqueue(pq, q_node);
    }

    dequeue(pq, &result);

    *tree = (HuffmanNode*)result.data;
}

void huffman_encode(HuffmanNode** tree, UCHAR* source, BitBuffer* encoded, HuffmanCode code_table[MAX_CHAR]){
    int i = 0;
    int j = 0;
    SymbolInfo symbol_info_table[MAX_CHAR];
    UCHAR temporary[MAX_BIT];

    for(i = 0; i < MAX_CHAR; i++){
        symbol_info_table[i].symbol = i;
        symbol_info_table[i].frequency = 0;
    }

    i = 0;
    while(source[i] != '\0'){
        symbol_info_table[source[i++]].frequency++;
    }

    huffman_buildPrefixTree(tree, symbol_info_table);
    huffman_buildCodeTable(*tree, code_table, temporary, 0);

    i = 0;
    while(source[i] != '\0'){
        int bit_count = code_table[source[i]].size;

        for(j = 0; j < bit_count; j++)
            huffman_addBit(encoded, code_table[source[i]].code[j]);

        i++;
    }
}

void huffman_decode(HuffmanNode* tree, BitBuffer* encoded, UCHAR* decoded){
    int i;
    int index = 0;
    HuffmanNode* current = tree;

    for(i = 0; i <= encoded->size; i++){
        UCHAR mask = 0x80;

        if(current->left == NULL && current->right == NULL){
            decoded[index++] = current->data.symbol;
            current = tree;
        }

        mask >>= i % 8;

        if((encoded->buffer[i / 8] & mask) != mask)
            current = current->left;
        else
            current = current->right;
    }

    decoded[index] = '\0';
}

void huffman_printBinary(BitBuffer* buffer){
    int i;

    for(i = 0; i < buffer->size; i++){
        UCHAR mask = 0x80;
        mask >>= i % 8;

        printf("%d", (buffer->buffer[i / 8] & mask) == mask);
    }
}