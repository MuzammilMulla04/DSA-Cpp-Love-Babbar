#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);

        // Count occurrences of each number in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++freq[grid[i][j]];
            }
        }

        vector<int> ans(2);
        // Find the repeated and missing numbers
        for (int num = 1; num <= n * n; ++num) {
            if (freq[num] == 2)
                ans[0] = num;  // Repeated number
            else if (freq[num] == 0)
                ans[1] = num;  // Missing number
        }
        return ans;
    }
};