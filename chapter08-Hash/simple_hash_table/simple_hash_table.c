#include "simple_hash_table.h"


HashTable* createHashTable(int table_size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->table_size = table_size;
    table->table = (Node*)malloc(sizeof(Node) * table->table_size);

    return table;
}

void set(HashTable* table, KeyType key, ValueType value){
    int address = hash(key, table->table_size);

    table->table[address].key = key;
    table->table[address].value = value;
}

ValueType get(HashTable* table, KeyType key){
    int address = hash(key, table->table_size);

    return table->table[address].value;
}

void destroyHashTable(HashTable* table){
    free(table->table);
    free(table);
}

int hash(KeyType key, int table_size){
    return key % table_size;
}
