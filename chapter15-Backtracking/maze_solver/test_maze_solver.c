#include "maze_solver.h"

int main(int argc, char* argv[]){
    int i = 0;
    int j = 0;

    MazeInfo maze;

    if(argc < 2){
        printf("Usage: maze_solver <MazeFile>\n");
        return 0;
    }

    if(getMaze(argv[1], &maze) == FAIL)
        return 0;

    if(solve(&maze) == FAIL)
        return 0;

    for(i = 0; i < maze.row_size; i++){
        for(j = 0; j < maze.column_size; j++){
            printf("%c", maze.data[i][j]);
        }

        printf("\n");
    }

    return 0;
}