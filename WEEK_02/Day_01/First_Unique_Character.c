#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s){
    int freq[26] = {0};

    for(int i=0; s[i] != '\0'; i++){
        freq[s[i] - 'a']++;
    }

    for(int i=0; s[i] != '\0'; i++){
        if(freq[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    char str1[] = "leetcode";
    char str2[] = "loveleetcode";
    char str3[] = "aabb";

    printf("Result for '%s': %d\n", str1, firstUniqChar(str1)); 
    printf("Result for '%s': %d\n", str2, firstUniqChar(str2)); 
    printf("Result for '%s': %d\n", str3, firstUniqChar(str3)); 

    return 0;
}
