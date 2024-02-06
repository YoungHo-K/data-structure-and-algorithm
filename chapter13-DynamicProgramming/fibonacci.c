#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG fibonacci(int n){
    int i;
    ULONG result;
    ULONG* fibonacci_table;

    if(n == 0 || n == 1)
        return n;
    
    fibonacci_table = (ULONG*)malloc(sizeof(ULONG) * (n + 1));
    fibonacci_table[0] = 0;
    fibonacci_table[1] = 1;

    for(i = 2; i <= n; i++){
        fibonacci_table[i] = fibonacci_table[i - 1] + fibonacci_table[i - 2];
    }

    result = fibonacci_table[n];

    free(fibonacci_table);

    return result;
}

int main(void){
    int n = 46;
    ULONG result = fibonacci(n);

    printf("Fibonacci(%d) = %lu\n", n, result);

    return 0;
}