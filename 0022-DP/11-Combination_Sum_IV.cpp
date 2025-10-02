#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve1(vector<int>& nums, int target) {
    if(target < 0)
        return 0;
    if(target == 0)
        return 1;

    int ways= 0;
    for(int& num: nums)
        ways += solve1(nums, target-num);

    return ways;
}
int findWays1(vector<int>& nums, int target) {
    return solve1(nums, target);
}

// 2. Recursion + Memoization
int solve2(vector<int>& nums, int target, vector<int>& dp) {
    if(target < 0)
        return 0;
    if(target == 0)
        return 1;
    
    if(dp[target] != -1)
        return dp[target];

    dp[target]= 0;
    for(int& num: nums)
        dp[target] += solve2(nums, target-num, dp);

    return dp[target];
}
int findWays2(vector<int>& nums, int target) {
    vector<int> dp(target+1, -1);
    return solve2(nums, target, dp);
}

// 3. Tabulation
int findWays3(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    dp[0]= 1;

    for(int i=1; i<=target; i++) {
        for(int& num: nums) {
            if(i-num >= 0)
                dp[i] += dp[i-num];
        }            
    }

    return dp[target];
}


int main() {
    system("cls");

    int T;
    cin >> T;
    vector<int> answers;

    while(T--) {
        int n, target;
        cin >> n >> target;

        vector<int> nums(n);
        for(int& num: nums)
            cin >> num;

        int ans= findWays3(nums, target);
        answers.push_back(ans);
    }

    cout << endl << "Ans: " << endl;
    for(int& ans: answers)
        cout << ans << endl;

    cout << endl;
    return 0;
}