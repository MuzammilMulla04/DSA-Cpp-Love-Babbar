#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        // dp[i][j] stores the length of the Fibonacci sequence ending at indices i and j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        // Iterate over each possible last element of the sequence
        for (int curr = 2; curr < n; curr++) {
            int left = 0, right = curr - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum < arr[curr]) {
                    left++;  // Need a larger sum, move left forward
                } else if (sum > arr[curr]) {
                    right--;  // Need a smaller sum, move right backward
                } else {
                    // Found a valid Fibonacci-like pair
                    dp[right][curr] = dp[left][right] + 1;
                    maxLen = max(maxLen, dp[right][curr]);

                    // Move both pointers inward to find other valid sequences
                    left++;
                    right--;
                }
            }
        }

        // If no valid sequence was found, return 0; otherwise, add 2 to include the first two numbers
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
