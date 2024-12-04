#include <iostream>
using namespace std;
int FirstZero(int arr[], int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0)
            return mid;

        if (arr[mid] == 1)
            return FirstZero(arr, mid + 1, high);
        else
            return FirstZero(arr, low, mid - 1);
    }
     
    return -1;
}

int countZeroes(int arr[], int n) {
    int firstZeroIndex = FirstZero(arr, 0, n - 1);

    if (firstZeroIndex == -1)
        return 0;

    return n - firstZeroIndex;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (1s followed by 0s):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Number of zeroes: " << countZeroes(arr, n) << endl;
    return 0;
}
