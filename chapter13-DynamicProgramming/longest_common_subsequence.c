#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct structLCSTable{
    int** data;
} LCSTable;

int LCS(char* X, char* Y, int i, int j, LCSTable* table){
    int m = 0;
    int n = 0;

    for(m = 0; m <= i; m++)
        table->data[m][0] = 0;
    
    for(n = 0; n <= j; n++)
        table->data[0][n] = 0;

    for(m = 1; m <= i; m++){
        for(n = 1; n <= j; n++){
            if(X[m - 1] == Y[n - 1])
                table->data[m][n] = table->data[m - 1][n - 1] + 1;
            else{
                if(table->data[m][n - 1] >= table->data[m - 1][n])
                    table->data[m][n] = table->data[m][n - 1];
                else
                    table->data[m][n] = table->data[m - 1][n];
            }
        }
    }

    return table->data[i][j];
}

void LCS_traceBack(char* X, char* Y, int m, int n, LCSTable* table, char* LCS){
    if(m == 0 || n == 0)
        return;

    if(table->data[m][n] > table->data[m][n - 1]
        && table->data[m][n] > table->data[m - 1][n]
        && table->data[m][n] > table->data[m - 1][n - 1])
    {
        char temp[100];
        strcpy(temp, LCS);
        sprintf(LCS, "%c%s", X[m - 1], temp);

        LCS_traceBack(X, Y, m - 1, n - 1, table, LCS);
    }
    else if(table->data[m][n] > table->data[m - 1][n]
            && table->data[m][n] == table->data[m][n - 1])
    {
        LCS_traceBack(X, Y, m, n - 1, table, LCS);
    }
    else
    {
        LCS_traceBack(X, Y, m - 1, n, table, LCS);
    }
}

void LCS_printTable(LCSTable* table, char* X, char* Y, int LEN_X, int LEN_Y){
    int i = 0;
    int j = 0;

    printf("%4s", "");

    for(i = 0; i < LEN_Y + 1; i++){
        printf("%c", Y[i]);
    }
    printf("\n");

    for(i = 0; i < LEN_X + 1; i++){

        if(i == 0)
            printf("%2s", "");
        else
            printf("%-2c", X[i - 1]);            

        for(j = 0; j < LEN_Y + 1; j++)
            printf("%d ", table->data[i][j]);

        printf("\n");
    }
}

int main(void){
    char* X = "GOOD MORNING.";
    char* Y = "GUTEN MORGEN.";
    char* result;

    int LEN_X = strlen(X);
    int LEN_Y = strlen(Y);

    int i = 0;
    int length = 0;
    LCSTable table;

    table.data = (int**)malloc(sizeof(int*) * (LEN_X + 1));
    for(i = 0; i < LEN_X + 1; i++){
        table.data[i] = (int*)malloc(sizeof(int) * (LEN_Y + 1));

        memset(table.data[i], 0, sizeof(int) * (LEN_Y + 1));
    }

    length = LCS(X, Y, LEN_X, LEN_Y, &table);

    LCS_printTable(&table, X, Y, LEN_X, LEN_Y);

    size_t table_size = sizeof(table.data[LEN_X][LEN_Y] + 1);
    result = (char*)malloc(table_size);
    memset(result, 0, table_size);

    LCS_traceBack(X, Y, LEN_X, LEN_Y, &table, result);

    printf("\n");
    printf("LCS:\"%s\" (Length: %d)\n", result, length);

    return 0;
}