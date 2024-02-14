#include "maze_solver.h"

int solve(MazeInfo* maze){
    int i = 0;
    int j = 0;
    int start_found = FAIL;
    int result = FAIL;

    Position start;

    for(i = 0; i < maze->column_size; i++){
        for(j = 0; j < maze->row_size; j++){
            if(maze->data[i][j] == START){
                start.x = j;
                start.y = i;
                start_found = SUCCEED;
                break;
            }
        }
    }

    if(start_found == FAIL)
        return FAIL;

    if(moveTo(maze, &start, NORTH))
        result = SUCCEED;

    else if(moveTo(maze, &start, SOUTH))
        result = SUCCEED;

    else if(moveTo(maze, &start, EAST))
        result = SUCCEED;

    else if(moveTo(maze, &start, WEST))
        result = SUCCEED;

    maze->data[start.y][start.x] = START;

    return result;
}

int moveTo(MazeInfo* maze, Position* current, int direction){
    int i = 0;
    int dirs[] = { NORTH, SOUTH, EAST, WEST };

    Position next;

    if(maze->data[current->y][current->x] == GOAL)
        return SUCCEED;

    maze->data[current->y][current->x] = MARKED;

    for(i = 0; i < 4; i++){
        if(getNextStep(maze, current, dirs[i], &next) == FAIL)
            continue;
        
        if(moveTo(maze, &next, dirs[i]) == SUCCEED)
            return SUCCEED;
    }

    maze->data[current->y][current->x] = WAY;

    return FAIL;
}

int getNextStep(MazeInfo* maze, Position* current, int direction, Position* next){
    switch(direction){
        case NORTH:
            next->x = current->x;
            next->y = current->y - 1;

            if(next->y == -1)
                return FAIL;
            
            break;

        case SOUTH:
            next->x = current->x;
            next->y = current->y + 1;

            if(next->y == maze->row_size)
                return FAIL;
            
            break;

        case EAST:
            next->x = current->x + 1;
            next->y = current->y;

            if(next->x == maze->column_size)
                return FAIL;
            
            break;            

        case WEST:
            next->x = current->x - 1;
            next->y = current->y;

            if(next->x == -1)
                return FAIL;
            
            break;            
    }

    if(maze->data[next->y][next->x] == WALL)
        return FAIL;

    if(maze->data[next->y][next->x] == MARKED)
        return FAIL;

    return SUCCEED;
}

int getMaze(char* file_path, MazeInfo* maze){
    int i = 0;
    int j = 0;
    int row_size = 0;
    int column_size = INIT_VALUE;

    FILE* fp;
    char buffer[MAX_BUFFER];

    if( (fp = fopen(file_path, "r")) == NULL ){
        printf("Cannot open file: %s\n", file_path);
        return FAIL;
    }

    while( fgets(buffer, MAX_BUFFER, fp) != NULL ){
        row_size++;
        
        if(column_size == INIT_VALUE)
            column_size = strlen(buffer) - 1;

        else if(column_size != strlen(buffer) - 1){
            printf("Maze data in file: %s is not valid.\n", file_path);
            fclose(fp);
            return FAIL;
        }
    }

    maze->row_size = row_size;
    maze->column_size = column_size;
    maze->data = (char**)malloc(sizeof(char*) * row_size);

    for(i = 0; i < row_size; i++)
        maze->data[i] = (char*)malloc(sizeof(char) * column_size);

    rewind(fp);

    for(i = 0; i < row_size; i++){
        fgets(buffer, MAX_BUFFER, fp);

        for(j = 0; j < column_size; j++)
            maze->data[i][j] = buffer[j];
    }

    fclose(fp);
    
    return SUCCEED;
}