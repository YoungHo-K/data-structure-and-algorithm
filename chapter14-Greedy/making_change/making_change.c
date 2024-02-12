#include "making_change.h"
#include <stdio.h>

void getChange(int price, int pay, int coin_units[], int change[], int size){
    int i = 0;
    int change_amount = pay - price;

    for(i = 0; i < size; i++){
        change[i] = countCoins(change_amount, coin_units[i]);
        change_amount = change_amount - (coin_units[i] * change[i]);
    }
}

int countCoins(int amount, int coin_unit){
    int coin_count = 0;
    int current_amount = amount;

    while(current_amount >= coin_unit){
        coin_count++;
        current_amount = current_amount - coin_unit;
    }

    return coin_count;
}

void printChange(int coin_units[], int change[], int size){
    int i = 0;

    for(i = 0; i < size; i++)
        printf("%8d원: %d개\n", coin_units[i], change[i]); 
}
