#include<bits/stdc++.h>
using namespace std;

// 1
int countDistinctWays1(int nStairs) {
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    return countDistinctWays1(nStairs-1) + countDistinctWays1(nStairs-2);
}

// 2
#define MOD 1000000007
int solve(int nStairs, vector<int>& dp) {
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    
    if(dp[nStairs] != -1)
        return dp[nStairs];

    dp[nStairs]= (solve(nStairs-1, dp) + solve(nStairs-2, dp))%MOD;
    return dp[nStairs];
}
int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1, -1);
    return solve(nStairs, dp);
}
