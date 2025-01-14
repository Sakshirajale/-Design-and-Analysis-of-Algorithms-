//Implement a problem of move all zeroes to end of array. 
//Statement: Given an array of random numbers, Push all the zero’s 
//of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, 
//it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same.  
//Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0}; 
//Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0}; 
#include <iostream>
using namespace std;

// Function to move all zeroes to the end of the array
void moveZeroesToEnd(int arr[], int n) {
    int count = 0;  // Count of non-zero elements

    // Traverse the array. If an element is non-zero, place it at the current index of `count`
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];  // Here count is incremented
        }
    }

    // After all non-zero elements have been placed, fill the rest of the array with zeroes
    while (count < n) {
        arr[count++] = 0;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test case 1
    int arr1[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array: ";
    printArray(arr1, n1);

    moveZeroesToEnd(arr1, n1);

    cout << "Array after moving zeroes: ";
    printArray(arr1, n1);

    // Test case 2
    int arr2[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "\nOriginal array: ";
    printArray(arr2, n2);

    moveZeroesToEnd(arr2, n2);

    cout << "Array after moving zeroes: ";
    printArray(arr2, n2);

    return 0;
}
