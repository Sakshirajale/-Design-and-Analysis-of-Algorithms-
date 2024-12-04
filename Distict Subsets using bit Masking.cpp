#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> findDistinctSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> uniqueSubsets;
    int n = nums.size();
    int totalSubsets = 1 << n; 
 
    for (int mask = 0; mask < totalSubsets; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
      
        uniqueSubsets.insert(subset);
    }
    
    vector<vector<int>> result(uniqueSubsets.begin(), uniqueSubsets.end());
    return result;
}

int main() {
    vector<int> S = {1, 2, 2};
    vector<vector<int>> subsets = findDistinctSubsets(S);
    
    cout << "{";
    for (const auto& subset : subsets) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "}, ";
    }
    cout << "}" << endl;

    return 0;
}
