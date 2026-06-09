#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result=(int*)malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    
    int head=0;
    int tail=numsSize - 1;
    
    for(int pos=numsSize-1; pos>=0; pos--) {
        int headSquare=nums[head]*nums[head];
        int tailSquare=nums[tail]*nums[tail];
        
        if (headSquare>tailSquare) {
            result[pos]=headSquare;
            head++;
        } else {
            result[pos]=tailSquare;
            tail--;
        }
    }
    
    return result;
}

int main() {
    int nums[] = {-4,-1,0,3,10};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize; 

    printf("Original Array: ");
    for (int i=0; i<numsSize; i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
    int* squaredArray=sortedSquares(nums,numsSize,&returnSize);
    printf("Squared & Sorted Array: ");
    for (int i=0; i<returnSize; i++) {
        printf("%d ",squaredArray[i]);
    }
    printf("\n");
    free(squaredArray);
    return 0;
}
