#include <stdio.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int rows=matSize;
    int columns=matColSize[0];

    if ((rows * columns) != (r*c)) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** output_arr = (int**)malloc(r*sizeof(int*));
    if (output_arr == NULL) return NULL; 

    *returnColumnSizes = (int*)malloc(r*sizeof(int));
    *returnSize = r;

    for (int i = 0; i < r; i++) {
        output_arr[i] = (int*)malloc(c*sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    int totalElements = r * c;
    for (int i=0; i<totalElements; i++) {
        int orig_r = i/columns;
        int orig_c = i%columns;
        int new_r = i/c;
        int new_c = i%c;

        output_arr[new_r][new_c] = mat[orig_r][orig_c];
    }

    return output_arr;
}

int main() {
    int test_rows=2;
    int test_cols=2;
    int r=1;
    int c=4;

    int** mat=(int**)malloc(test_rows * sizeof(int*));
    for (int i = 0; i < test_rows; i++) {
        mat[i]=(int*)malloc(test_cols * sizeof(int));
    }
    mat[0][0]=1;mat[0][1]=2;
    mat[1][0]=3;mat[1][1]=4;

    int matColSize[2]={test_cols, test_cols};

    int returnSize;
    int* returnColumnSizes;

     int** result = matrixReshape(mat,test_rows,matColSize,r,c,&returnSize,&returnColumnSizes);

    printf("Reshaped Matrix [%dx%d]:\n", returnSize, returnColumnSizes[0]);
    for (int i=0; i<returnSize; i++) {
        printf("[ ");
        for (int j=0; j<returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("]\n");
    }

    if (result != mat) {
        for (int i=0; i<returnSize; i++) {
            free(result[i]);
        }
        free(result);
        free(returnColumnSizes);
    }

    for (int i=0; i<test_rows; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
