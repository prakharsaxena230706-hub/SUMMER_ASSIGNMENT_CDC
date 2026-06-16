#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2) return false;
    int s1_count[26] = {0};
    int s2_count[26] = {0};
    for (int i = 0; i < len1; i++) {
        s1_count[s1[i] - 'a']++;
        s2_count[s2[i] - 'a']++;
    }
    for (int i = 0; i <= len2 - len1; i++) {
        bool is_match = true;
        for (int j = 0; j < 26; j++) {
            if (s1_count[j] != s2_count[j]) {
                is_match = false;
                break;
            }
        }
        if (is_match) return true;
        if (i < len2 - len1) {
            s2_count[s2[i + len1] - 'a']++;
            s2_count[s2[i] - 'a']--;
        }
    }
    return false;
}

int main(void) {
    char s1[] = "ab";
    char s2[] = "eidbaooo";
    if (checkInclusion(s1, s2)){
        printf("True\n");
    } 
    else{
        printf("False\n");
    }
    return 0;
}
