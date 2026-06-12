#include <stdio.h>

void reverseString(char* s, int sSize);

int main(){
    char testStr[] = {'h','e','l','l','o'};
    int size = sizeof(testStr)/sizeof(testStr[0]);

    // Print original string
    printf("Original: ");
    for(int i=0; i<size; i++){
        printf("%c", testStr[i]);
    }
    printf("\n");

    reverseString(testStr, size);

    printf("Reversed: ");
    for(int i=0; i<size; i++){
        printf("%c", testStr[i]);
    }
    printf("\n");
    return 0;
}

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize-1;
    
    while(left<right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
