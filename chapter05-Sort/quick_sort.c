#include <stdio.h>


void swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int partition(int dataset[], int left, int right){
    int first = left;
    int pivot = dataset[first];

    ++left;

    while(left <= right){
        while(dataset[left] <= pivot && left < right)
            ++left;

        while(dataset[right] >= pivot && left <= right)
            --right;
        
        if(left < right)
            swap(&dataset[left], &dataset[right]);
        else
            break;
    }

    swap(&dataset[first], &dataset[right]);

    return right;
}

void quickSort(int dataset[], int left, int right){
    if(left < right){
        int index = partition(dataset, left, right);

        quickSort(dataset, left, index - 1);
        quickSort(dataset, index + 1, right);
    }
}

int main(void){
    int dataset[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(dataset) / sizeof(dataset[0]);
    int i = 0;

    quickSort(dataset, 0, length - 1);
    
    for(i = 0; i < length; i++){
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;    
}