#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }

    int mini = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        int cost = prices[i] - mini;
        
        if (cost > maxProfit) {
            maxProfit = cost;
        }
        
        if (prices[i] < mini) {
            mini = prices[i];
        }
    }

    return maxProfit;
}

int main() {
    int n;

    printf("Enter number of days: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input size.\n");
        return 1;
    }

    int* prices = (int*)malloc(n * sizeof(int));
    if (prices == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the stock prices for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &prices[i]) != 1) {
            printf("Invalid input data.\n");
            free(prices);
            return 1;
        }
    }

    int result = maxProfit(prices, n);
    printf("\nMaximum Profit: %d\n", result);

    free(prices);
    return 0;
}
