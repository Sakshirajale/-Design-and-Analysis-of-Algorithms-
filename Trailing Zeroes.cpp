#include <iostream>
using namespace std;
int countTrailingZeroes(int x) {
    int count = 0;
   for (int i = 5; x / i >= 1; i *= 5) {
        count += x / i;
    }
    return count;
}

int findSmallestNumber(int n) {
    if (n == 0) {
        return 0; // 0! = 1, which has no trailing zeroes
    }

    int low = 0;
    int high = 5 * n; 
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int zeroes = countTrailingZeroes(mid);

        if (zeroes >= n) {
            result = mid; 
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeroes needed: ";
    cin >> n;
    cout << "The smallest number whose factorial contains at least " << n << " trailing zeroes is: " << findSmallestNumber(n) << endl;

    return 0;
}
