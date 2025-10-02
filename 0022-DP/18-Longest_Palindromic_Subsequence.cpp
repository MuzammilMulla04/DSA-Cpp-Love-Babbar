#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Filling the DP table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];  // Expand palindrome
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  // Exclude one character
            }
        }

        return dp[0][n - 1];  // Longest Palindromic Subsequence in the entire string
    }
};