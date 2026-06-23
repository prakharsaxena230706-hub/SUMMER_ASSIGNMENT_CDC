#include <stdio.h>
#include <string.h>

char* reverseWords(char* s){
    int left = 0;
    int right = 0;
    int len = strlen(s);

    while (right <= len){
        if (s[right] == ' ' || s[right] == '\0') {
            int i=left;
            int j=right-1;
            while (i < j) {
                char temp = s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            left=right+1;
        }
        right++;
    }
    return s;
}

int main() {
    char str[] = "Welcome to this world!";
    printf("Original: %s\n", str);
    
    reverseWords(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}
