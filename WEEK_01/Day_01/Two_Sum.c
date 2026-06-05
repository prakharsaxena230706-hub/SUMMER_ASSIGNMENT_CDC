#include <stdio.h>
#include <stdlib.h>
// BRUTE FORCE APPROACH
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }


    *returnSize = 0;
    free(result); 
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 18;
    int returnSize;
    printf("Input Array: [2, 7, 11, 15], Target: %d\n", target);

    
    int* indices = twoSum(nums, numsSize, target, &returnSize);

    
    if (indices != NULL && returnSize == 2) {
        printf("Indices found: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
