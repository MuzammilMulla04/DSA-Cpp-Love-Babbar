#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve1(vector<int>& coins, int amount) {
    if(amount < 0)
        return INT_MAX;
    if(amount == 0)
        return 0;
    
    int minCount= INT_MAX;
    for(int& coin: coins) {
        int ans= solve1(coins, amount - coin);

        if(ans != INT_MAX)
            minCount= min(minCount, ans+1);
    }

    return minCount;
}
int minimumElements(vector<int>& coins, int amount) {
    int ans= solve1(coins, amount);
    return ans == INT_MAX? -1: ans;
}

// 2. Recursion + Memoization
int solve2(vector<int>& coins, int amount, vector<int>& dp) {
    if(amount < 0)
        return INT_MAX;
    if(amount == 0)
        return 0;
    if(dp[amount] != -1)
        return dp[amount];

    dp[amount]= INT_MAX;
    for(int& coin: coins) {
        int ans= solve2(coins, amount - coin, dp);

        if(ans != INT_MAX)
            dp[amount]= min(dp[amount], ans+1);
    }

    return dp[amount];
}
int minimumElements(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans= solve2(coins, amount, dp);
    return ans == INT_MAX? -1: ans;
}

// 3. Tabulation
int minimumElements(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0]= 0;
    
    for(int i=1; i <= amount; i++) {
        for(int& coin: coins) {
            if(i-coin >= 0 && dp[i-coin] != INT_MAX)
                dp[i]= min(dp[i], dp[i-coin] + 1);
        }
    }

    return dp[amount] == INT_MAX? -1: dp[amount];
}



int main() {
    system("cls");

    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n, 0);
    for(int& coin: coins)
        cin >> coin;

    int ans= minimumElements(coins, amount);
    cout << ans << endl;

    return 0;
}