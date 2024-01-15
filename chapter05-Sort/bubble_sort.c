#include <stdio.h>

void bubbleSort(int dataset[], int length){
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 0; i < length - 1; i++){
        for(j = 0; j < length - (i + 1); j++){
            if(dataset[j] > dataset[j + 1]){
                temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }
}


int main(void){
    int dataset[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(dataset) / sizeof(dataset[0]);
    int i = 0;

    bubbleSort(dataset, length);

    for(i = 0; i < length; i++){
        printf("%d ", dataset[i]);
    }

    printf("\n");

    return 0;
}