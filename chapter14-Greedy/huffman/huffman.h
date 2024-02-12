#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct TagSymbolInfo{
    UCHAR symbol;
    int frequency;
} SymbolInfo;

typedef struct TagHuffmanNode{
    SymbolInfo data;
    struct TagHuffmanNode* left;
    struct TagHuffmanNode* right;
} HuffmanNode;

typedef struct TagBitBuffer{
    UCHAR* buffer;
    UINT size;
} BitBuffer;

typedef struct TagHuffmanCode{
    UCHAR code[MAX_BIT];
    int size;
} HuffmanCode;

HuffmanNode* huffman_createNode(SymbolInfo data);
void         huffman_destroyNode(HuffmanNode* node);
void         huffman_destroyTree(HuffmanNode* node);
void         huffman_addBit(BitBuffer* buffer, char value);

void         huffman_encode(HuffmanNode** tree, UCHAR* source, BitBuffer* encoded, HuffmanCode code_table[MAX_CHAR]);
void         huffman_decode(HuffmanNode* tree, BitBuffer* encoded, UCHAR* decoded);
void         huffman_buildPrefixTree(HuffmanNode** tree, SymbolInfo symbol_info_table[MAX_CHAR]);
void         huffman_buildCodeTable(HuffmanNode* tree, HuffmanCode code_table[MAX_CHAR], UCHAR code[MAX_BIT], int size);
void         huffman_printBinary(BitBuffer* buffer);

#endif
