#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b){
    return strcmp(*(const char**)a, *(const char**)b);
}

char* longestCommonPrefix(char** strs, int strsSize){
    if(strsSize == 0){
        char *empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    
    if(strsSize == 1){
        char *single = (char*)malloc(strlen(strs[0]) + 1);
        strcpy(single, strs[0]);
        return single;
    }

    qsort(strs,strsSize,sizeof(char*),compareStrings);

    char *first = strs[0];
    char *last = strs[strsSize-1];
    
    int maxLen = strlen(first);
    char *result = (char*)malloc(maxLen+1);
    
    int i=0;
    while(i<strlen(first) && i<strlen(last)){
        if(first[i] != last[i]){
            break;
        }
        result[i] = first[i];
        i++;
    }
    result[i] = '\0'; 
    return result;
}

int main(){
    char *arr[] = {"club","clap","clove"};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Input Array: ");
    for(int i=0; i<size; i++){
        printf("\"%s\" ", arr[i]);
    }
    printf("\n");

    char *prefix = longestCommonPrefix(arr,size);
    
    printf("Longest Common Prefix: \"%s\"\n", prefix);
    free(prefix);
    return 0;
}
