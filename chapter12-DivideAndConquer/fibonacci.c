#include <stdio.h>

typedef unsigned long ULONG;

typedef struct tagMatrix2x2{
    ULONG data[2][2];
} Matrix2x2;


Matrix2x2 multiply(Matrix2x2 A, Matrix2x2 B){
    Matrix2x2 C;

    C.data[0][0] = A.data[0][0] * B.data[0][0] + A.data[0][1] * B.data[1][0];
    C.data[0][1] = A.data[0][0] * B.data[1][0] + A.data[0][1] * B.data[1][1];

    C.data[1][0] = A.data[1][0] * B.data[0][0] + A.data[1][1] * B.data[1][0];
    C.data[1][1] = A.data[1][0] * B.data[1][0] + A.data[1][1] * B.data[1][1];

    return C;
}

Matrix2x2 power(Matrix2x2 A, int n){
    if(n > 1){
        A = power(A, n / 2);
        A = multiply(A, A);

        if(n & 1){
            Matrix2x2 B;
            B.data[0][0] = 1;
            B.data[0][1] = 1;
            B.data[1][0] = 1;
            B.data[1][1] = 0;

            A = multiply(A, B);
        }
    }
    
    return A;
}

ULONG fibonacci(int n){
    Matrix2x2 A;
    A.data[0][0] = 1;
    A.data[0][1] = 1;
    A.data[1][0] = 1;
    A.data[1][1] = 0;

    A = power(A, n);

    return A.data[0][1];
}

int main(void){
    int   n      = 46;
    ULONG result = fibonacci(n);

    printf("Fibonacci(%d) = %lu\n", n, result);

    return 0;
}