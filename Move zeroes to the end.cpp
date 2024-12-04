#include <iostream>
using namespace std;

void moveZeroesToEnd(int arr[], int n) {
    int nonZeroIndex = 0; // Tracks the position to place non-zero elements

    // Traverse the array and move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }

    // Fill the remaining positions with zeroes
    while (nonZeroIndex < n) {
        arr[nonZeroIndex++] = 0;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZeroesToEnd(arr, n);

    cout << "Array after moving zeroes to the end:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
