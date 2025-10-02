#include <bits/stdc++.h>
using namespace std;

const int mod= 1e9 + 7;
// 1. Recursion
long long int countDerangements(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    return (n-1) * (countDerangements(n-1) + countDerangements(n-2)) % mod;
}

// 2. Recursion + Memoization
long long int solve(int n, vector<long long int>& dp) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    dp[n]= (n-1) * (solve(n-1, dp) + solve(n-2, dp)) % mod;
    return dp[n];
}
long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);

    return solve(n, dp);
}

// 3. Tabulation
long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    dp[1]= 0;
    dp[2]= 1;

    for(int i= 3; i<=n; i++)
        dp[i]= (i-1) * (dp[i-1] + dp[i-2]) % mod;

    return dp[n];
}

// 4. Space Optimized
long long int countDerangements(int n) {
    vector<long long int> dp= {0, 1, 0};

    for(int i=1; i<=n; i++) {
        dp[2]= (i-1) * (dp[0] + dp[1]) % mod;

        dp[0]= dp[1];
        dp[1]= dp[2];
    }

    return dp[2];
}