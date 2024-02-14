#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define INIT_VALUE -1

#define START  'S'
#define GOAL   'G'
#define WAY    ' '
#define WALL   '#'
#define MARKED '+'


enum DIRECTION { NORTH, SOUTH, EAST, WEST };
enum RESULT    { FAIL, SUCCEED };

typedef struct tagPosition{
    int x;
    int y;
} Position;

typedef struct tagMazeInfo{
    int column_size;
    int row_size;

    char** data;
} MazeInfo;

int solve(MazeInfo* maze);
int moveTo(MazeInfo* maze, Position* current, int direction);
int getNextStep(MazeInfo* maze, Position* current, int direction, Position* next);
int getMaze(char* file_path, MazeInfo* maze);

#endif
