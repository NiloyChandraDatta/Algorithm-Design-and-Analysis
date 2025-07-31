#include <bits/stdc++.h>
using namespace std;

#define mx 1000
int dp[mx][mx];  // dp array for memoization

// Function to find the minimum number of coins
int minCoins(int coins[], int n, int target_amount)
{
    if (target_amount == 0) 
        return 0;  // No coins needed if target is 0

    if (target_amount < 0 || n == 0) 
        return 1e9;  // Impossible if target is negative or no coins left

    if (dp[n][target_amount] == -1) {
        dp[n][target_amount] = min(minCoins(coins, n, target_amount - coins[n-1]) + 1,
                                   minCoins(coins, n-1, target_amount));  // Take or skip coin
    }

    return dp[n][target_amount];  // Return result from dp
}

int main()
{
    int coins[] = {1, 2, 3};  // Coin denominations
    int n = 3;  // Number of coins
    int target_amount = 5;  // Target amount
    
    memset(dp, -1, sizeof(dp));  // Initialize dp array

    cout << minCoins(coins, n, target_amount) << endl;  // Print result

    return 0;
}
