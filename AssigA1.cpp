#include <iostream>
using namespace std;

// Function to count the number of 0s in the array
int countZeroes(int arr[], int n) {
    // Start iterating from the end of the array
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        // If a 0 is found, increment the count
        if (arr[i] == 0) {
            count++;
        } 
        // Since all 1s are before 0s, break the loop when a 1 is encountered
        else {
            break;
        }
    }
    return count;
}

int main() {
    // Test Case 1
    int arr1[] = {1, 1, 1, 1, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Number of 0s: " << countZeroes(arr1, n1) << endl;

    // Test Case 2
    int arr2[] = {1, 0, 0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Number of 0s: " << countZeroes(arr2, n2) << endl;

    return 0;
}
