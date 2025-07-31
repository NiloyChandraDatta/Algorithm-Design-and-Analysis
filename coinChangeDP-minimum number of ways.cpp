#include<bits/stdc++.h>
using namespace std;

#define mx 1000  // Max size for dp array
int dp[mx][mx];

int counts(int coins[], int n, int target_amount)
{
    if (target_amount == 0) 
        dp[n][target_amount] = 1;  // 1 way to make 0 (no coins)

    if (target_amount < 0 || n == 0) 
        dp[n][target_amount] = 0;  // No way if target is negative or no coins left

    if(dp[n][target_amount] == -1)
        dp[n][target_amount] = counts(coins, n, target_amount - coins[n-1]) + 
                               counts(coins, n - 1, target_amount);  // Include or exclude current coin

    return dp[n][target_amount];
}

int main()
{
    int coins[] = {1, 2, 3};  // Coin denominations
    int n = 3;  // Number of coin types
    int target_amount = 5;  // Target amount

    memset(dp, -1, sizeof(dp));  // Initialize dp array

    cout << counts(coins, n, target_amount) << endl;  // Output result

    return 0;
}
