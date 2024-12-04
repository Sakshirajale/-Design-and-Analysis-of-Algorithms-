#include <iostream>

using namespace std;

// Function to check if there is a subset with the given sum
bool subsetSum(int set[], int N, int sum) {
    // Create a 2D dp array to store the results of subproblems
    bool dp[N + 1][sum + 1];

    // Initialize the first column as true (0 sum is possible with empty set)
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row as false (no sum possible with non-empty set)
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }

    // Fill the dp table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                // Include the current element or exclude it
                dp[i][j] = dp[i - 1][j - set[i - 1]] || dp[i - 1][j];
            } else {
                // Exclude the current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][sum]; // Return the result for the full set and the given sum
}

int main() {
    int set1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int N1 = sizeof(set1) / sizeof(set1[0]);
    cout << "Input: set[] = {3, 34, 4, 12, 5, 2}, sum = " << sum1 << ", Output: " 
         << (subsetSum(set1, N1, sum1) ? "True" : "False") << endl;

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int N2 = sizeof(set2) / sizeof(set2[0]);
    cout << "Input: set[] = {3, 34, 4, 12, 5, 2}, sum = " << sum2 << ", Output: " 
         << (subsetSum(set2, N2, sum2) ? "True" : "False") << endl;

    return 0;
}
