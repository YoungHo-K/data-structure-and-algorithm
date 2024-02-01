#include <stdio.h>
#include <string.h>
#include "boyer_moore.h"

#define MAX_BUFFER 512


int main(int argc, char** argv){
    char* file_path;
    FILE* fp;

    char  text[MAX_BUFFER];
    char* pattern;
    int   pattern_size = 0;
    int   line         = 0;

    if(argc < 3){
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
        return 1;
    }

    file_path = argv[1];
    pattern = argv[2];

    pattern_size = strlen(pattern);

    if( (fp = fopen(file_path, "r")) == NULL ){
        printf("Cannot open file: %s\n", file_path);
        return 1;
    }

    while(fgets(text, MAX_BUFFER, fp) != NULL){
        int position = boyerMoore(text, strlen(text), 0, pattern, pattern_size);

        line++;

        if(position >= 0){
            printf("line: %d, column: %d : %s", line, position + 1, text);
        }
    }

    fclose(fp);

    return 0;
}