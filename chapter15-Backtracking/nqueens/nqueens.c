#include "nqueens.h"

#include <stdio.h>
#include <stdlib.h>

void findSolutionForQueen(int columns[], int row, int number_of_queens, int* solution_count){
    if(isThreatened(columns, row))
        return;

    if(row == number_of_queens - 1){
        printf("Solution #%d : \n", ++(*solution_count));
        printSolution(columns, number_of_queens);
    }
    else{
        int i;
        for(i = 0; i < number_of_queens; i++){
            columns[row + 1] = i;
            findSolutionForQueen(columns, row + 1, number_of_queens, solution_count);
        }
    }
}

int isThreatened(int columns[], int row){
    int current_row = 0;
    int threatened = 0;

    while(current_row < row){
        if(columns[row] == columns[current_row] 
            || abs(columns[row] - columns[current_row]) == abs(row - current_row))
        {
            threatened = 1;
            break;
        }
        
        current_row++;
    }

    return threatened;
}

void printSolution(int columns[], int number_of_queens){
    int i = 0;
    int j = 0;

    for(i = 0; i < number_of_queens; i++){
        for(j = 0; j < number_of_queens; j++){
            if(columns[i] == j)
                printf("Q");
            else
                printf(".");
        }

        printf("\n");
    }

    printf("\n");
}