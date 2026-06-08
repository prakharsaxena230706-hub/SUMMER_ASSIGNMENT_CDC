#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    long long maxSum = sum;
    int startIndex = 0;
    int endIndex = k;
    
    while (endIndex < numsSize) {
        sum -= nums[startIndex];
        startIndex++;
        
        sum += nums[endIndex];
        endIndex++;
        
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return (double)maxSum / k;
}

int main() {
    
    int nums[] = {1, 12, -5, -6, 50, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]); 
    int k = 4;

    double result = findMaxAverage(nums, numsSize, k);
    printf("Maximum Average Subarray: %.5f\n", result);

    return 0;
}
