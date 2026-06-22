#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    if (needle[0] == '\0') return 0;
    
    int needleLen = strlen(needle);
    int haystackLen = strlen(haystack);
    
    int *lps = (int *)malloc(sizeof(int) * needleLen);
    if (lps == NULL) return -1;
    
    for (int idx = 0; idx < needleLen; idx++) {
        lps[idx] = 0;
    }
    
    int prevLPS = 0;
    int i = 1;
    while(i < needleLen){
        if (needle[i] == needle[prevLPS]){
            lps[i] = prevLPS + 1;
            prevLPS++;
            i++;
        } 
        else{
            if (prevLPS == 0){
                lps[i] = 0;
                i++;
            } 
            else{
                prevLPS = lps[prevLPS - 1];
            }
        }
    }
    
    i = 0;
    int j = 0;
    while (i < haystackLen){
        if (haystack[i] == needle[j]){
            i++;
            j++;
        }
        else{
            if (j == 0){
                i++;
            } 
            else{
                j = lps[j - 1];
            }
        }
        if (j == needleLen){
            free(lps);
            return i - needleLen;
        }
    }
    
    free(lps);
    return -1;
}

int main(void) {
    char haystack[] = "sadbutsad";
    char needle[] = "sad";
    int index = strStr(haystack, needle);
    printf("Index: %d\n", index);
    return 0;
}
