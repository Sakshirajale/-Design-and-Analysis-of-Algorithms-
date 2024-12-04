#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Function to calculate the cost of converting a matrix to a magic square
int calculateCost(const vector<vector<int>>& matrix, const vector<vector<int>>& magicSquare) {
    int cost = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cost += abs(matrix[i][j] - magicSquare[i][j]);
        }
    }
    return cost;
}

int main() {
    // Input 3x3 matrix
    vector<vector<int>> matrix(3, vector<int>(3));
    cout << "Enter the 3x3 matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Predefined all possible 3x3 magic squares
    vector<vector<vector<int>>> magicSquares = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    // Initialize the minimum cost to a very large value
    int minCost = INT_MAX;

    // Compare the input matrix with each magic square
    for (const auto& magicSquare : magicSquares) {
        int cost = calculateCost(matrix, magicSquare);
        minCost = min(minCost, cost);
    }

    // Output the minimum cost
    cout << "Minimum cost to convert the matrix into a magic square: " << minCost << endl;

    return 0;
}
