#include <stdio.h>
#include <string.h>


void insertionSort(int dataset[], int length){
     int i = 0;
     int j = 0;
     int value = 0;

     for(i = 1; i < length; i++){
        if(dataset[i - 1] < dataset[i])
            continue;
        
        value = dataset[i];
        for(j = 0; j < i; j++){
            if(dataset[j] > value){
                memmove(&dataset[j + 1], &dataset[j], sizeof(dataset[0]) * (i - j));
                dataset[j] = value;
                break;
            }
        }
     }
}

int main(void){
    int dataset[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(dataset) / sizeof(dataset[0]);
    int i = 0;

    insertionSort(dataset, length);
    
    for(i = 0; i < length; i++){
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}