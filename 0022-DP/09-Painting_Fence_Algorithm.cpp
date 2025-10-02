#include <bits/stdc++.h>
using namespace std;

const int mod= 1e9 + 7;

// 1. Recursion
int numberOfWays(int n, int k) {
    if(n == 1)
        return k;
    if(n == 2)
        return k*k;
    
    return (k-1) * (numberOfWays(n-1, k) + numberOfWays(n-2, k)) % mod;
}

// 2. Recursion + Memoization
int solve(int n, int k, vector<int>& dp) {
    if(n == 1)
        return k;
    if(n == 2)
        return k*k;
    
    if(dp[n] != -1)
        return dp[n];
    
    dp[n]= (k-1) * 1LL * (solve(n-1, k, dp) + solve(n-2, k, dp)) % mod;
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return solve(n, k, dp);
}

// 3. Tabulation
int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    dp[1]= k;
    dp[2]= k*k;
    
    for(int i=3; i<=n; i++)
        dp[i]= (k-1) * 1LL * (dp[i-1] + dp[i-2]) % mod;

    return dp[n];
}

// 4. Space Optimized
int numberOfWays(int n, int k) {
    if(n == 1)
        return k;
    if(n == 2)
        return k*k;

    vector<int> dp(3, -1);
    dp[0]= k;
    dp[1]= k*k;    

    for(int i=3; i<=n; i++) {
        dp[2]= (k-1) * 1LL * (dp[0] + dp[1]) % mod;

        dp[0]= dp[1];
        dp[1]= dp[2];
    }

    return dp[2];
}
