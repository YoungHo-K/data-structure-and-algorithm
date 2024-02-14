#include <stdio.h>
#include <stdlib.h>
#include "nqueens.h"

int main(int argc, char* argv[]){
    int i                = 0;
    int number_of_queens = 0;
    int solution_count   = 0;
    int* columns;

    if(argc < 2){
        printf("Usage: %s <Number of Queens>", argv[0]);
        return 1;
    }

    number_of_queens = atoi(argv[1]);
    columns = (int*)calloc(number_of_queens, sizeof(int));

    for(i = 0; i < number_of_queens; i++){
        columns[0] = i;
        findSolutionForQueen(columns, 0, number_of_queens, &solution_count);
    }

    free(columns);

    return 0;
}