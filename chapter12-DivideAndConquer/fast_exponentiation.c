#include <stdio.h>

typedef unsigned long ULONG;


ULONG power(int base, int exponent){
    if(exponent == 1)
        return base;
    else if(base == 0)
        return 1;

    if(exponent % 2 == 0){
        ULONG new_base = power(base, exponent / 2);
        return new_base * new_base;
    }
    else{
        ULONG new_base = power(base, (exponent - 1) / 2);
        return new_base * new_base * base;
    }
}

int main(void){
    int base     = 2;
    int exponent = 30;

    printf("%d%d = %lu\n", base, exponent, power(base, exponent));

    return 0;
}