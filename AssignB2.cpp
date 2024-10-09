#include <iostream>
#include <climits>
using namespace std;

// Function to calculate the maximum profit
int maxProfit(int arr[], int n) {
    int minPrice = INT_MAX;  // Minimum price to buy the stock
    int maxProfit = 0;       // Maximum profit we can make

    // Traverse through the array
    for (int i = 0; i < n; i++) {
        // Update the minimum price encountered so far
        if (arr[i] < minPrice) {
            minPrice = arr[i];
        }

        // Calculate the profit by selling the stock on day i
        int profit = arr[i] - minPrice;

        // Update the maximum profit if the current profit is greater
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main() {
    // Test case 1
    int arr1[] = {2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum Profit: " << maxProfit(arr1, n1) << endl;

    // Test case 2
    int arr2[] = {8, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Maximum Profit: " << maxProfit(arr2, n2) << endl;

    return 0;
}
