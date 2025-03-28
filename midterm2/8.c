// 8. Given a rod of length n and an array price[] where price[i] represents the price of a rod
// of length i+1, find the optimal way to cut the rod into smaller pieces to maximize the profit.
// Example: price[] = {1, 5, 8, 9, 10, 17, 17, 20}, then Rod length is 4.
// Hint: The idea is to fill the dp table from bottom to up. For each rod of length i, starting
// from i = 1 to i = n, find the maximum value that can obtained by cutting it into two pieces
// of length j and (i − j).
// Implement the function rodCut in C to solve the problem using dynamic programming, and
// make sure to print the maximum profit for a rod of length 4.
#include <stdio.h>
#include <limits.h>
int max(int a, int b) {
    if (a > b) {
        return a;
    }else {
        return b;
    }
}
int rodCut(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int max_rev = INT_MIN;
        for(int j= 0; j < i; j++){
            max_rev = max(max_rev, price[j] + dp[i - (j + 1)]);
        }

        dp[i] = max_rev;
        printf("dp[%d]: ", i);
        for (int k = 0; k <= i; k++) {
            printf("%d ", dp[k]);
        }
        printf("\n");
    }
    return dp[n];
}
int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_length = 4;
    int n = sizeof(price) / sizeof(price[0]);
    int max_profit = rodCut(price, rod_length);
    printf("Maximum profit for a rod of length %d: %d\n", rod_length, max_profit);
    return 0;
}