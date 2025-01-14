//Implement a problem of activity selection problem with K persons. 
//Statement: Given two arrays S[] and E[] of size N denoting starting and closing time of the shops and an integer value K denoting the 
//number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based 
//on the following conditions: 
//1)A shop can be visited by only one person 
//2) A person cannot visit another shop if its timing collide with it 
//Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2  Output: 4 
//Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2  Output: 3 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a shop with start and end time
struct Shop {
    int start, end;
};

// Function to sort the shops by their ending times
bool compare(Shop a, Shop b) {
    return a.end < b.end;
}

// Function to find the maximum number of shops that K persons can visit
int maxShopsVisit(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    vector<Shop> shops(N);

    // Create the shops with their start and end times
    for (int i = 0; i < N; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    // Sort shops by their end times
    sort(shops.begin(), shops.end(), compare);

    // Array to store the end times of the last shop visited by each person
    vector<int> personEndTimes(K, 0);

    int count = 0;  // Total number of shops visited

    // Greedily assign shops to persons
    for (int i = 0; i < N; i++) {
        // Find the person whose last visited shop ends the earliest and doesn't overlap
        int person = -1;
        for (int j = 0; j < K; j++) {
            if (personEndTimes[j] <= shops[i].start) {
                if (person == -1 || personEndTimes[j] < personEndTimes[person]) {
                    person = j;
                }
            }
        }

        // If we found a person who can visit the shop, assign the shop to them
        if (person != -1) {
            personEndTimes[person] = shops[i].end;  // Update the end time for the person
            count++;  // Increment the count of shops visited
        }
    }

    return count;
}

int main() {
    // Test Case 1
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited: " << maxShopsVisit(S1, E1, K1) << endl;

    // Test Case 2
    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShopsVisit(S2, E2, K2) << endl;

    return 0;
}
