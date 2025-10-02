#include <bits/stdc++.h>
using namespace std;

// 2DP??

// 1. Recursion
bool solve(vector<int>& arr, int index, int sum, int target) {
    if(index > arr.size())
        return sum == target;

    if(sum > target)
        return false;
    
    bool exclude= solve(arr, index+1, sum, target);
    bool include= solve(arr, index+1, sum+arr[index], target);

    return exclude || include;
}
bool subsetSumToK(int n, int target, vector<int> &arr) {
    return solve(arr, 0, 0, target);
}

// 2. Recursion + Memoization
bool solve(vector<int>& arr, int index, int sum, int target, vector<int>& dp) {
    if(index < 0)
        return sum == target;
    if(sum > target)
        return false;
    if(dp[index] != 0)
        return dp[index];
    
    bool exclude= solve(arr, index-1, sum, target, dp);
    bool include= solve(arr, index-1, sum+arr[index], target, dp);

    dp[index]= exclude || include;
    return dp[index];
}
bool subsetSumToK(int n, int target, vector<int> &arr) {
    vector<int> dp(n+1, false);
    return solve(arr, n-1, 0, target, dp);
}

// 3. Tabulation
bool solve(vector<int>& arr, int index, int sum, int target, vector<int>& dp) {
    if(index < 0)
        return sum == target;
    if(sum > target)
        return false;
    if(dp[index] != 0)
        return dp[index];
    
    bool exclude= solve(arr, index-1, sum, target, dp);
    bool include= solve(arr, index-1, sum+arr[index], target, dp);

    dp[index]= exclude || include;
    return dp[index];
}
bool subsetSumToK(int n, int target, vector<int> &arr) {
    vector<int> dp(target+1, false);

    dp[0]= 0;
    for(int i=0; i<=target; i++) {
        for(int j= 1; j<=i; j++) {
            bool exclude= dp[j-1] == i;
            bool include= dp[j-1] + arr[j] == i;

            dp[j]= exclude || include;
        }
    }

    return dp[n];
}