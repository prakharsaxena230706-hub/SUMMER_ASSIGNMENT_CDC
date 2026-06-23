#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool repeatedSubstringPattern(char *s){
    int len = strlen(s);
    char *dup = malloc(2*len + 1);
    if (!dup) return false;
    strcpy(dup, s);
    strcpy(dup+len, s);
    dup[2*len-1] = '\0';
    bool result = strstr(dup+1, s) != NULL;
    free(dup);
    return result;
}

int main() {
    char *test1 = "abab";
    char *test2 = "aba";
    char *test3 = "abcabcabcabc";
    printf("Test 1 ('abab'): %s\n", repeatedSubstringPattern(test1) ? "true" : "false");
    printf("Test 2 ('aba'): %s\n", repeatedSubstringPattern(test2) ? "true" : "false");
    printf("Test 3 ('abcabcabcabc'): %s\n", repeatedSubstringPattern(test3) ? "true" : "false");
    return 0;
}
