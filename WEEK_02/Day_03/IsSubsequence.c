#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(const char *s, const char *t){
    while (*t && *s){
        if (*s == *t){
            s++;
        }
        t++;
    }
    return *s == '\0';
}

int main(void) {
    char s1[] = "abc";
    char t1[] = "ahbgdc";
    printf("%s\n", isSubsequence(s1, t1) ? "true" : "false");
    char s2[] = "axc";
    char t2[] = "ahbgdc";
    printf("%s\n", isSubsequence(s2, t2) ? "true" : "false");
    return 0;
}
