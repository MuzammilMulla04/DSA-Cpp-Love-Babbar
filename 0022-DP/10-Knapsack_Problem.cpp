#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    if(n == 0) {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    
// Exclude
    int exclude= solve(weight, value, n-1, maxWeight);
// Include
    int include= 0;
    if(weight[n] <= maxWeight)
        include= value[n] + solve(weight, value, n-1, maxWeight - weight[n]);

    return max(exclude, include);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return solve(weight, value, n-1, maxWeight);
}

// 2. Recursion + Memoization
int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight, vector<vector<int>>& dp) {
    if(n == 0) {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if(dp[n][maxWeight] != -1)
        return dp[n][maxWeight];
    
// Exclude
    int exclude= solve(weight, value, n-1, maxWeight);
// Include
    int include= 0;
    if(weight[n] <= maxWeight)
        include= value[n] + solve(weight, value, n-1, maxWeight - weight[n]);

    dp[n][maxWeight]= max(exclude, include);
    return dp[n][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
    return solve(weight, value, n-1, maxWeight, dp);
}

// 3. Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, 0));

    for(int w= weight[0]; w <= maxWeight; w++) {
        dp[0][w]= weight[0] <= maxWeight? value[0]: 0;
    }

    for(int i=1; i<n; i++) {
        for(int w=0; w<=maxWeight; w++) {
        // Exclude
            int exclude= dp[i-1][w];
        // Include
            int include= 0;
            if(weight[i] <= w)
                include= value[i] + dp[i-1][w-weight[i]];
        // Take Max
            dp[i][w]= max(exclude, include);
        }
    }
    return dp[n-1][maxWeight];
}

// 4. Space Optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    for(int w= weight[0]; w <= maxWeight; w++)
        prev[w]= weight[0] <= maxWeight? value[0]: 0;

    for(int i=1; i<n; i++) {
        for(int w=0; w<=maxWeight; w++) {
        // Exclude
            int exclude= prev[w];
        // Include
            int include= 0;
            if(weight[i] <= w)
                include= value[i] + prev[w-weight[i]];
        // Take Max
            curr[w]= max(exclude, include);
        }

        prev= curr;
    }
    return prev[maxWeight];
}

// 5. Ultra-Space Optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> curr(maxWeight+1, 0);

    for(int w= weight[0]; w <= maxWeight; w++)
        curr[w]= weight[0] <= maxWeight? value[0]: 0;

    for(int i=1; i<n; i++) {
        for(int w=maxWeight; w>=0; w--) {
        // Exclude
            int exclude= curr[w];
        // Include
            int include= 0;
            if(weight[i] <= w)
                include= value[i] + curr[w-weight[i]];
        // Take Max
            curr[w]= max(exclude, include);
        }
    }
    return curr[maxWeight];
}

