#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s), pLen = strlen(p);
    if (sLen < pLen){
        *returnSize = 0;
        return NULL;
    }
    int pCount[26] = {0}, sCount[26] = {0};
    for (int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a']++;
    }
    int* result = (int*)malloc(sizeof(int) * sLen);
    if (!result){
        *returnSize = 0;
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < sLen; i++) {
        sCount[s[i] - 'a']++;
        if (i >= pLen) {
            sCount[s[i-pLen] - 'a']--;
        }
        if (i >= pLen-1) {
            bool isMatch = true;
            for (int j = 0; j < 26; j++) {
                if (pCount[j] != sCount[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) result[count++] = i-pLen+1;
        }
    }
    *returnSize = count;
    return result;
}

int main() {
    char s[] = "cbaebabacd", p[] = "abc";
    int returnSize = 0;
    int* indices = findAnagrams(s, p, &returnSize);
    printf("Indices: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", indices[i], (i < returnSize-1) ? ", " : "");
    }
    printf("]\n");
    free(indices);
    return 0;
}
