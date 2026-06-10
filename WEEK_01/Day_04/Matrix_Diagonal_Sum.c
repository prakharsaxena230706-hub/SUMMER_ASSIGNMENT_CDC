#include <stdio.h>

int diagonalSum(int n, int mat[n][n]) {
    int sum = 0;
    
    for (int i=0; i<n; i++) {
        sum += mat[i][i];       // Primary diagonal
        sum += mat[i][n-i-1]; // Secondary diagonal
    }
    
    // If the matrix has an odd dimension, remove the double-counted center element
    if ( n%2 != 0) {
        sum -= mat[n/2][n/2];
    }
    return sum;
}

int main(void) {
    int n=3;
    int matrix[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    int result=diagonalSum(n,matrix);
    
    printf("Matrix Diagonal Sum: %d\n", result);
    
    return 0;
}
