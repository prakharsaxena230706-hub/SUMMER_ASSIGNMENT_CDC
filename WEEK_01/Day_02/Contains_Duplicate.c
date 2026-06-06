#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

bool containsDuplicate(int *nums,int numsSize) {
    if (nums==NULL || numsSize<=1) {
        return false;
    }

    qsort(nums,numsSize,sizeof(int),compare);

    for (int i=0; i<numsSize-1; i++) {
        if (nums[i] == nums[i+1]){
            return true; 
        }
    }
    return false;
}

int main() {    
    int testArray[] = {1,3,4,2,3,5};
    int size = sizeof(testArray) / sizeof(testArray[0]);
    printf("Test Result: %s\n", containsDuplicate(testArray,size) ? "True (Duplicate Found)" : "False");
    return 0;
}
