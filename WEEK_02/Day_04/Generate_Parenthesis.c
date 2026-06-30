#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current, int open, int close, int n) {
    int len = strlen(current);
    if (len == 2 * n){
        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    if (open < n){
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, n);
        current[len] = '\0';
    }
    if (close < open){
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, n);
        current[len] = '\0';
    }
}

char **generateParenthesis(int n, int *returnSize){
    int maxResults = 15000;
    char **result = malloc(maxResults * sizeof(char *));
    *returnSize = 0;
    char *current = malloc((2 * n + 1) * sizeof(char));
    current[0] = '\0';
    backtrack(result, returnSize, current, 0, 0, n);
    free(current);
    return result;
}

int main(){
    int n = 3;
    int returnSize = 0;
    char **arr = generateParenthesis(n, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++){
        printf("\"%s\"", arr[i]);
        if (i < returnSize - 1) printf(",");
        free(arr[i]);
    }
    printf("]\n");
    free(arr);
    return 0;
}
