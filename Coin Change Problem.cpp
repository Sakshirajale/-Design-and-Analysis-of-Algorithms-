/*Implement Coin Change problem.
#include <iostream>

using namespace std;

// Function to find the number of ways to make the sum using coins
int coinChange(int sum, int coins[], int N) {
    // Create a dp array to store the number of ways to make each amount
    int dp[sum + 1] = {0};  // Initialize all elements to 0

    // Base case: There is one way to make sum 0 (using no coins)
    dp[0] = 1;

    // Loop through each coin
    for (int i = 0; i < N; i++) {
        int coin = coins[i];
        // Update the dp array for all amounts from coin to sum
        for (int j = coin; j <= sum; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[sum];
}

int main() {
    int sum1 = 4;
    int coins1[] = {1, 2, 3};
    int N1 = sizeof(coins1) / sizeof(coins1[0]);
    cout << "Input: sum = " << sum1 << ", coins[] = {1, 2, 3}, Output: " << coinChange(sum1, coins1, N1) << endl;

    int sum2 = 10;
    int coins2[] = {2, 5, 3, 6};
    int N2 = sizeof(coins2) / sizeof(coins2[0]);
    cout << "Input: sum = " << sum2 << ", coins[] = {2, 5, 3, 6}, Output: " << coinChange(sum2, coins2, N2) << endl;

    return 0;
}
