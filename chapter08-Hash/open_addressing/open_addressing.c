#include "open_addressing.h"


HashTable* createHashTable(int table_size){
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (ElementType*)malloc(sizeof(ElementType) * table_size);

    memset(ht->table, 0, sizeof(ElementType) * table_size);

    ht->table_size = table_size;
    ht->occupied_count = 0;

    return ht;
}

void set(HashTable** ht, KeyType key, ValueType value){
    int key_length, address, step_size;
    double usage;

    usage = (double)(*ht)->occupied_count / (*ht)->table_size;
    if(usage > 0.5)
        rehash(ht);

    key_length = strlen(key);
    address = hash(key, key_length, (*ht)->table_size);
    step_size = hash2(key, key_length, (*ht)->table_size);

    while((*ht)->table[address].status != EMPTY && strcmp((*ht)->table[address].key, key) != 0){
        printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n", key, address, step_size);

        address = (address + step_size) % (*ht)->table_size;
    }

    (*ht)->table[address].key = (char*)malloc(sizeof(char) * (key_length + 1));
    strcpy((*ht)->table[address].key, key);

    (*ht)->table[address].value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy((*ht)->table[address].value, value);

    (*ht)->table[address].status = OCCUPIED;
    (*ht)->occupied_count++;

    printf("Key(%s) entered at address(%d)\n", key, address);
}

ValueType get(HashTable* ht, KeyType key){
    int key_length = strlen(key);
    int address = hash(key, key_length, ht->table_size);
    int step_size = hash2(key, key_length, ht->table_size);

    while(ht->table[address].status != EMPTY && strcmp(ht->table[address].key, key) != 0){
        address = (address + step_size) % ht->table_size;
    }

    return ht->table[address].value;
}

void clearElement(ElementType* element){
    if(element->status == EMPTY)
        return;

    free(element->key);
    free(element->value);
}

void destroyHashTable(HashTable* ht){
    int i = 0;
    for(i = 0; i < ht->table_size; i++){
        clearElement(&(ht->table[i]));
    }

    free(ht->table);
    free(ht);
}

int hash(KeyType key, int key_length, int table_size){
    int i = 0;
    int hash_value = 0;

    for(i = 0; i < key_length; i++){
        hash_value = (hash_value << 3) + key[i];
    }

    hash_value = hash_value % table_size;

    return hash_value;
}

int hash2(KeyType key, int key_length, int table_size){
    int i = 0;
    int hash_value = 0;

    for(i = 0; i < key_length; i++){
        hash_value = (hash_value << 2) + key[i];
    }

    hash_value = hash_value % (table_size - 3);

    return hash_value + 1;
}

void rehash(HashTable** ht){
    int i = 0;
    ElementType* old_table = (*ht)->table;

    HashTable* new_ht = createHashTable((*ht)->table_size * 2);
    printf("\nRehashed. New table size is: %d\n\n", new_ht->table_size);

    for(i = 0; i < (*ht)->table_size; i++){
        if(old_table[i].status == OCCUPIED)
            set(&new_ht, old_table[i].key, old_table[i].value);
    }

    destroyHashTable((*ht));

    (*ht) = new_ht;
}
