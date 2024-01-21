#include "chaining.h"


HashTable* createHashTable(int table_size){
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table_size = table_size;
    ht->table = (List*)malloc(sizeof(Node) * ht->table_size);

    memset(ht->table, 0, sizeof(List) * table_size);

    return ht;
}

void destroyHashTable(HashTable* ht){
    int i = 0;
    for(i = 0; i < ht->table_size; i++){
        List the_list = ht->table[i];
        destroyList(the_list);
    }

    free(ht->table);
    free(ht);
}

Node* createNode(KeyType key, ValueType value){
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(node->key, key);

    node->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(node->value, value);

    node->next = NULL;

    return node;
}

void destroyNode(Node* node){
    free(node->key);
    free(node->value);
    free(node);
}

void destroyList(List the_list){
    if(the_list == NULL)
        return;
    
    if(the_list->next != NULL)
        destroyList(the_list->next);

    destroyNode(the_list);
}

void set(HashTable* ht, KeyType key, ValueType value){
    int address = hash(key, strlen(key), ht->table_size);
    Node* node = createNode(key, value);

    if(ht->table[address] == NULL)
        ht->table[address] = node;
    else{
        List l = ht->table[address];
        node->next = l;
        ht->table[address] = node;

        printf("Collision occured: Key(%s), Address(%d)\n", key, address);
    }
}

ValueType get(HashTable* ht, KeyType key){
    int address = hash(key, strlen(key), ht->table_size);

    List the_list = ht->table[address];
    List target = NULL;

    if(the_list == NULL)
        return NULL;
    
    while(1){
        if(strcmp(the_list->key, key) == 0){
            target = the_list;
            break;
        }

        if(the_list->next == NULL)
            break;
        else
            the_list = the_list->next;
    }

    return target->value;
}

int hash(KeyType key, int key_length, int table_size){
    int i = 0;
    int hash_value = 0;

    for(i = 0; i < key_length; i++){
        hash_value = (hash_value << 3) + key[i];
    }

    return hash_value % table_size;
}
