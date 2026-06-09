#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int nonzero=0; 
    for (int i=0; i<numsSize; i++) {
        if (nums[i]!=0) {
            int temp=nums[i];
            nums[i]=nums[nonzero];
            nums[nonzero]=temp;
            nonzero++;
        }
    }
}

int main() {
    int nums[]={0,1,0,3,12};
    int numsSize=sizeof(nums)/sizeof(nums[0]);

    printf("Original array: ");
    for (int i=0; i<numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    moveZeroes(nums,numsSize);

    printf("Modified array: ");
    for (int i=0; i<numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
