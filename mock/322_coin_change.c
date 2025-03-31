// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/coin-change/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b){
    return a < b ? a : b;
}


int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    for(int i = 0; i <= amount; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i = 0; i < coinsSize; i++){
        int coin = coins[i];

        for(int j = coin; j <= amount; j++){
            if(dp[j - coin] != INT_MAX){
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX? -1 : dp[amount];
}

int main(){
    int coins[] = {1, 2, 5};
    int coinsSize = 3;
    int amount = 11;

    // int coins[] = {2};
    // int coinsSize = 1;
    // int amount = 3;

    int min_change = coinChange(coins, coinsSize, amount);
    if(min_change == -1){
        printf("The amount of money cannot be made up by any combination of the coins.\n");
    }else{
        printf("The fewest number of coins that we need to make up that amount: %d\n", min_change);
    }

    return 0;
}