#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while(left<right){
        while(left<right && !isalnum((unsigned char)s[left])){
            left++;
        }
        while(left<right && !isalnum((unsigned char)s[right])){
            right--;
        }
        
        if(tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(void){
    char testString[] = "A man, a plan, a canal: Panama";
   
    if(isPalindrome(testString)){
        printf("Result: True (It is a valid palindrome)\n");
    } 
    else{
        printf("Result: False (It is NOT a valid palindrome)\n");
    }
    return 0;
}
