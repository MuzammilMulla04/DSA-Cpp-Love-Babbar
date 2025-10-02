#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution1 {
    int solve(int n) {
        if(n <= 0)
            return 0;
        
        int minWays= INT_MAX;
        for(int i=1; i*i<=n; i++) {
            minWays= min(minWays, solve(n - i*i) + 1);
        }

        return minWays;
    }
  public:
    int MinSquares(int n) {
        return solve(n);
    }
};

// 2. Recursion + Memoization
class Solution2 {
    int solve(int n, vector<int>& dp) {
        if(n <= 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        int minWays= INT_MAX;
        for(int i=1; i*i<=n; i++) {
            minWays= min(minWays, solve(n - i*i, dp) + 1);
        }

        dp[n]= minWays;
        return dp[n];
    }
  public:
    int MinSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// 3. Tabulation
class Solution3 {
public:
    int MinSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]= 0;

        for(int num=1; num <= n; num++) {
            for(int i=1; i*i <= num; i++) {
                dp[num]= min(dp[num], dp[num - i*i] + 1);
            }

        }

        return dp[n];
    }
};

