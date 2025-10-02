#include<bits/stdc++.h>
using namespace std;

// 1
class Solution {
    int solve(vector<int>& cost, int n) {
        if(n < 2)
            return cost[n];

        int ans= cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();

        int ans= min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

// 2
class Solution2 {
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if(n < 2)
            return cost[n];

        if(dp[n] != -1)
            return dp[n];

        dp[n]= cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1, -1);

        int ans= min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};

// 3
class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1, -1);

        dp[0]= cost[0];
        dp[1]= cost[1];

        for(int i=2; i<n; i++)
            dp[i]= min(dp[i-1], dp[i-2]) + cost[i];

        dp[n]= min(dp[n-1], dp[n-2]);

        return dp[n];
    }
};

// 4
class Solution4 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int prev1= cost[0];
        int prev2= cost[1];

        for(int i=2; i<n; i++) {
            int curr= min(prev1, prev2) + cost[i];
            prev2= prev1;
            prev1= curr;
        }

        int curr= min(prev1, prev2);
        return curr;
    }
};
