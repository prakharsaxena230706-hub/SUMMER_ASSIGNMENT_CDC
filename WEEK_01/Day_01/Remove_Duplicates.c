#include <stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, numsSize);
    
    printf("Number of unique elements (k): %d\n", k);
    printf("Modified array (first %d elements): ", k);
    for (int m = 0; m < k; m++) {
        printf("%d ", nums[m]);
    }
    printf("\n");

    return 0;
}
