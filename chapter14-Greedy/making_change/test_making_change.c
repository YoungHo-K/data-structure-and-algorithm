#include "making_change.h"
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int _a = *(int*)a;
    int _b = *(int*)b;

    if(_a < _b)
        return 1;
    else
        return -1;
}

int main(void){
    int  i          = 0;
    int  pay        = 0;
    int  price      = 0;
    int  unit_count = 0;
    int* coin_units = NULL;
    int* change     = NULL;

    printf("동전의 가짓수를 입력하세요 :");
    scanf("%d", &unit_count);

    coin_units = (int*)malloc(sizeof(int) * unit_count);
    change     = (int*)malloc(sizeof(int) * unit_count);

    for(i = 0; i < unit_count; i++){
        printf("[%d] 번째 동전의 단위를 입력하세요: ", i);
        scanf("%d", &coin_units[i]);
    }

    qsort(coin_units, unit_count, sizeof(int), compare);

    printf("물건 가격을 입력하세요: ");
    scanf("%d", &price);

    printf("손님이 지불한 돈은 얼마입니까?: ");
    scanf("%d", &pay);
    
    getChange(price, pay, coin_units, change, unit_count);

    printChange(coin_units, change, unit_count);

    return 0;
}