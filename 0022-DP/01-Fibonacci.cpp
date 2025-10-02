#include<bits/stdc++.h>
using namespace std;

// 1. Top-Down Approach: Recursion + Memoization
int fibonacci1(int n, vector<int>& dp) {
    if(n < 2)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    dp[n]= fibonacci1(n-1, dp) + fibonacci1(n-2, dp);
    return dp[n];
}

// 2. Bottom-Up Approach: Tabulation
int fibonacci2(int n) {
    vector<int> dp(n+1, -1);
    dp[0]= 0;
    dp[1]= 1;

    for(int i=2; i<=n; i++)
        dp[n]= dp[n-1] + dp[n-2];

    return dp[n];
}

// 3. Space optimization
int fibonacci3(int n) {
    int curr= 0, prev1= 1, prev2= 0;

    for(int i=2; i<=n; i++) {
        curr= prev1 + prev2;
        prev2= prev1;
        prev1= curr;
    }

    return curr;
}

int main() {
    int n;
    cin >> n;
    n--;

    cout << fibonacci3(n);
}