#include<stdio.h>
#include<stdlib.h>

// Kadane's Algorithm 
int maxSubArraySum(int arr[], int n)
{
    long long maxi = arr[0];
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi){
            maxi = sum;
        }

        if (sum < 0){
            sum = 0;
        }
    }

    if (maxi < 0){
        return 0;
    }

    return maxi;
}

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long result = maxSubArraySum(arr, n);
    printf("The maximum subarray sum is: %lld\n", result);
    return 0;
}
