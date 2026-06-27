#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(const char* s){
    int len = strlen(s);
    int stackCap = 100;
    int* countsStack = (int*)malloc(stackCap * sizeof(int));
    char** stringStack = (char**)malloc(stackCap * sizeof(char*));
    int stackTop = -1;

    int currCap = 128;
    char* currStr = (char*)malloc(currCap * sizeof(char));
    currStr[0] = '\0';
    int currLen = 0;

    int i = 0;
    while (i < len){
        if (isdigit(s[i])){
            int count = 0;
            while (i < len && isdigit(s[i])){
                count = count * 10 + (s[i] - '0');
                i++;
            }

            stackTop++;
            if (stackTop >= stackCap){
                stackCap *= 2;
                countsStack = (int*)realloc(countsStack, stackCap * sizeof(int));
                stringStack = (char**)realloc(stringStack, stackCap * sizeof(char*));
            }
            countsStack[stackTop] = count;
            stringStack[stackTop] = strdup(currStr);

            currStr[0] = '\0';
            currLen = 0;
        } 
        else if (s[i] == '[') i++;
        else if (s[i] == ']'){
            int repeatTimes = countsStack[stackTop];
            char* prevStr = stringStack[stackTop];
            stackTop--;

            int prevLen = strlen(prevStr);
            int newLen = prevLen + (currLen * repeatTimes);

            if (newLen + 1 >= currCap){
                currCap = newLen + 128;
                currStr = (char*)realloc(currStr, currCap * sizeof(char));
            }

            char* tempBuf = (char*)malloc((newLen + 1) * sizeof(char));
            strcpy(tempBuf, prevStr);
            
            int offset = prevLen;
            for (int r = 0; r < repeatTimes; r++){
                strcpy(tempBuf + offset, currStr);
                offset += currLen;
            }

            free(currStr);
            free(prevStr);
            currStr = tempBuf;
            currLen = newLen;
            currCap = newLen + 1;
            i++;
        } 
        else{
            if (currLen + 2 >= currCap){
                currCap *= 2;
                currStr = (char*)realloc(currStr, currCap * sizeof(char));
            }
            currStr[currLen++] = s[i];
            currStr[currLen] = '\0';
            i++;
        }
    }

    free(countsStack);
    free(stringStack);
    return currStr;
}

int main(void){
    const char* testStr = "3[a]2[bc]";
    char* decoded = decodeString(testStr);
    
    printf("Input:  %s\n", testStr);
    printf("Output: %s\n", decoded);
    
    free(decoded);
    return 0;
}
