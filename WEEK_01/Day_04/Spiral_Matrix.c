#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if(matrixSize == 0 || matrixColSize[0] == 0){
        *returnSize = 0;
        return NULL;
    }

    int n=matrixSize, m=matrixColSize[0];
    *returnSize = n*m;
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    int idx=0;

    int left=0, right = m-1;
    int top=0, bottom = n-1;

    while(top <= bottom && left <= right){
        for(int i=left; i<=right; i++) ans[idx++] = matrix[top][i];
        top++;

        for(int i=top; i<=bottom; i++) ans[idx++] = matrix[i][right];
        right--;

        if(top <= bottom){
            for(int i=right; i>=left; i--) ans[idx++] = matrix[bottom][i];
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i>=top; i--) ans[idx++] = matrix[i][left];
            left++;
        }
    }
    return ans;
}

int main(){
    int rows=3, cols=4;
    int testMatrix[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j=0; j<cols; j++) matrix[i][j] = testMatrix[i][j];
    }

    int matrixColSize[3] = {cols,cols,cols};
    int returnSize = 0;

    int* result = spiralOrder(matrix,rows,matrixColSize,&returnSize);

    for(int i=0; i<returnSize; i++) printf("%d ",result[i]);
    printf("\n");
    free(result);
    for(int i=0; i<rows; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
