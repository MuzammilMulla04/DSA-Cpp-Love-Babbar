#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
// Approach 1
void solve(vector<int>& nums, int index, int sum, int& maxSum) {
    if(index >= nums.size()) {
        maxSum= max(sum, maxSum);
        return;
    }

// Exclude
    solve(nums, index+1, sum, maxSum);
// Include
    solve(nums, index+2, sum+nums[index], maxSum);
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int maxSum= 0;
    solve(nums, 0, 0, maxSum);
    return maxSum;
}

// Approach 2
int solve(vector<int>& nums, int index) {
    if(index < 0)
        return 0;
    if(index == 0)
        return nums[0];
    
// Exclude
    int excludeSum= solve(nums, index-1);
// Include
    int includeSum= solve(nums, index-2) + nums[index];

    return max(excludeSum, includeSum);
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int n= nums.size();
    int maxSum= solve(nums, n-1);
    return maxSum;
}

// 2. Recursion + Memoization
int solve(vector<int>& nums, int index, vector<int>& dp) {
    if(index < 0)
        return 0;
    if(index == 0)
        return nums[0];
    
// Exclude
    int excludeSum= dp[index-1] == -1? solve(nums, index-1, dp): dp[index-1];
// Include
    int includeSum= dp[index-2] == -1? solve(nums, index-2, dp) + nums[index]: dp[index-2] + nums[index];

    dp[index]= max(excludeSum, includeSum);
    return dp[index];
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int n= nums.size();
    vector<int> dp(n, -1);
    int maxSum= solve(nums, n-1, dp);
    return maxSum;
}

// 3. Tabulation
int solve(vector<int>& nums, int n) {
    vector<int> dp(n, -1);
    dp[0]= nums[0];
    dp[1]= max(nums[0], nums[1]);

    for(int index= 2; index < n; index++) {
    // Exclude
        int excludeSum= dp[index-1];
    // Include
        int includeSum= dp[index-2] + nums[index];

        dp[index]= max(excludeSum, includeSum);
    }

    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int n= nums.size();

    int maxSum= solve(nums, n);
    return maxSum;
}

// 4. Space Optimized
int solve(vector<int>& nums, int n) {
    vector<int> dp(3, 0);
    
    for(int& num: nums) {
        dp[2]= max(dp[1], dp[0] + num);

        dp[0]= dp[1];
        dp[1]= dp[2];
    }

    return dp[2];
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int n= nums.size();

    int maxSum= solve(nums, n);
    return maxSum;
}

