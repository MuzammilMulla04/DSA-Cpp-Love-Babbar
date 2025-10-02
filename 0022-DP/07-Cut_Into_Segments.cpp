#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve(int length, int x, int y, int z) {
    if(length < 0)
        return INT_MIN;
	if(length == 0)
		return 0;

    int ans1= solve(length-x, x, y, z);
    int ans2= solve(length-y, x, y, z);
    int ans3= solve(length-z, x, y, z);

    return max(ans1, max(ans2, ans3)) + 1;
}
int cutSegments(int n, int x, int y, int z) {
    int ans= solve(n, x, y, z);
	return ans < 0? 0: ans;
}

// 2. Recursion + Memoization
int solve(int length, int x, int y, int z, vector<int>& dp) {
    if(length < 0)
        return INT_MIN;
	if(length == 0)
		return 0;
    if(dp[length] != INT_MIN)
        return dp[length];

    int ans1= solve(length-x, x, y, z, dp);
    int ans2= solve(length-y, x, y, z, dp);
    int ans3= solve(length-z, x, y, z, dp);

    dp[length]= max(ans1, max(ans2, ans3)) + 1;
    return dp[length];
}
int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n+1, INT_MIN);
    int ans= solve(n, x, y, z, dp);
	return ans < 0? 0: ans;
}

// 3. Tabulation
int solve(int length, int x, int y, int z) {
    vector<int> dp(length+1, INT_MIN);
    dp[0]= 0;

    for(int i=1; i<=length; i++) {
        int ans1= i-x >= 0? dp[i-x]: INT_MIN;
        int ans2= i-y >= 0? dp[i-y]: INT_MIN;
        int ans3= i-z >= 0? dp[i-z]: INT_MIN;

        dp[i]= max(ans1, max(ans2, ans3)) + 1;
    }

    return dp[length] < 0? 0: dp[length];
}
int cutSegments(int n, int x, int y, int z) {
    return solve(n, x, y, z);
}
