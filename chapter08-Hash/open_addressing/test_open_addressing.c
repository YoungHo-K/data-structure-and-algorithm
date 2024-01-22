#include "open_addressing.h"


int main(void){
    HashTable* ht = createHashTable(11);

    set(&ht, "MSFT", "Microsoft Corporation");
    set(&ht, "JAVA", "Sun Microsystems");
    set(&ht, "REDH", "Red Hat Linux");
    set(&ht, "APAC", "Apache Org");
    set(&ht, "ZYMZZ", "Unisys Ops Check");
    set(&ht, "IBM", "IBM Ltd.");
    set(&ht, "ORCL", "Oracle Corporation");
    set(&ht, "CSCO", "Cisco Systems, Inc.");
    set(&ht, "GOOG", "Google Inc.");
    set(&ht, "YHOO", "Yahoo! Inc.");
    set(&ht, "NOVL", "Novell, Inc.");

    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT", get(ht, "MSFT"));
    printf("Key:%s, Value:%s\n", "JAVA", get(ht, "JAVA"));
    printf("Key:%s, Value:%s\n", "REDH", get(ht, "REDH"));
    printf("Key:%s, Value:%s\n", "APAC", get(ht, "APAC"));
    printf("Key:%s, Value:%s\n", "ZYMZZ", get(ht, "ZYMZZ"));
    printf("Key:%s, Value:%s\n", "IBM", get(ht, "IBM"));
    printf("Key:%s, Value:%s\n", "ORCL", get(ht, "ORCL"));
    printf("Key:%s, Value:%s\n", "CSCO", get(ht, "CSCO"));
    printf("Key:%s, Value:%s\n", "GOOG", get(ht, "GOOG"));
    printf("Key:%s, Value:%s\n", "YHOO", get(ht, "YHOO"));
    printf("Key:%s, Value:%s\n", "NOVL", get(ht, "NOVL"));

    destroyHashTable(ht);

    return 0;
}