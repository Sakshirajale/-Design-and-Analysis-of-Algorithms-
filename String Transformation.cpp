#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

bool canTransform(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    
    // Create a DP table of size (m+1) x (n+1)
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // Base case: It is always possible to match an empty s2 by deleting all of s1
    dp[0][0] = true;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] && islower(s1[i - 1]); // Delete lowercase letters
        
        for (int j = 1; j <= n; j++) {
            if (toupper(s1[i - 1]) == s2[j - 1]) {
                // Case 1: Match current character by converting lowercase to uppercase
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (islower(s1[i - 1])) {
                // Case 2: Skip the current lowercase character
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1, s2;
    
    // Test case 1
    s1 = "daBcd";
    s2 = "ABC";
    if (canTransform(s1, s2)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    // Test case 2
    s1 = "argaju";
    s2 = "RAJ";
    if (canTransform(s1, s2)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}
