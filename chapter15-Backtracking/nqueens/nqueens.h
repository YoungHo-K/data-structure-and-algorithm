#ifndef NQUEENS_H
#define NQUEENS_H

void printSolution(int columns[], int number_of_queens);
int  isThreatened(int columns[], int row);
void findSolutionForQueen(int columns[], int row, int number_of_queens, int* solution_count);

#endif
