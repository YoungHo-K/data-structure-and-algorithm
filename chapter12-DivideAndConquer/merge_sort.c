#include <stdio.h>
#include <stdlib.h>


void mergeSort(int dataset[], int start_index, int end_index);
void merge(int dataset[], int start_index, int middle_index, int end_index);


void mergeSort(int dataset[], int start_index, int end_index){
    int middle_index;

    if(end_index - start_index < 1)
        return;

    middle_index = (start_index + end_index) / 2;

    mergeSort(dataset, start_index, middle_index);
    mergeSort(dataset, middle_index + 1, end_index);

    merge(dataset, start_index, middle_index, end_index);
}

void merge(int dataset[], int start_index, int middle_index, int end_index){
    int i;
    int left_index = start_index;
    int right_index = middle_index + 1;
    int dest_index = 0;

    int* destination = (int*)malloc(sizeof(int) * (end_index - start_index + 1));
    
    while(left_index <= middle_index && right_index <= end_index){
        if(dataset[left_index] < dataset[right_index]){
            destination[dest_index] = dataset[left_index];
            left_index++;
        }
        else{
            destination[dest_index] = dataset[right_index];
            right_index++;
        }

        dest_index++;
    }

    while(left_index <= middle_index)
        destination[dest_index++] = dataset[left_index++];
    
    while(right_index <= end_index)
        destination[dest_index++] = dataset[right_index++];

    dest_index = 0;
    for(i = start_index; i <= end_index; i++)
        dataset[i] = destination[dest_index++];
    
    free(destination);
}

int main(void){
    int dataset[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
    int length = sizeof(dataset) / sizeof(int);
    int i = 0;

    mergeSort(dataset, 0, length - 1);

    for(i = 0; i < length; i++)
        printf("%d ", dataset[i]);

    printf("\n");

    return 0;
}
