#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve1(vector<int>& days, int index, vector<int>& cost) {
    if(index >= days.size())
        return 0;

    int pass_1days= cost[0] + solve1(days, index + 1, cost);

    int newIndex= index;
    while(days[newIndex] < days[index] + 7)
        newIndex++;
    int pass_7days= cost[1] + solve1(days, newIndex, cost);

    newIndex= index;
    while(days[newIndex] < days[index] + 30)
        newIndex++;
    int pass_30days= cost[2] + solve1(days, newIndex, cost);

    return min(pass_1days, min(pass_7days, pass_30days));
}
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    return solve1(days, 0, cost);
}

// 2. Recursion + Memoization
int solve2(vector<int>& days, int index, vector<int>& cost, vector<int>& dp) {
    if(index >= days.size())
        return 0;

    if(dp[index] != -1)
        return dp[index];

    int pass_1days= cost[0] + solve2(days, index + 1, cost, dp);

    int newIndex= index;
    while(days[newIndex] < days[index] + 7)
        newIndex++;
    int pass_7days= cost[1] + solve2(days, newIndex, cost, dp);

    newIndex= index;
    while(days[newIndex] < days[index] + 30)
        newIndex++;
    int pass_30days= cost[2] + solve2(days, newIndex, cost, dp);

    dp[index]= min(pass_1days, min(pass_7days, pass_30days));
    return dp[index];
}
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    vector<int> dp(n + 1, -1);
    return solve2(days, 0, cost, dp);
}

// 3. Tabulation
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    vector<int> dp(n+1, INT_MAX);
    dp[n]= 0;

    for(int index= n-1; index >= 0; index--) {
        int pass_1days= cost[0] + dp[index + 1];

        int newIndex= index;
        while(days[newIndex] < days[index] + 7)
            newIndex++;
        int pass_7days= cost[1] + dp[newIndex];

        newIndex= index;
        while(days[newIndex] < days[index] + 30)
            newIndex++;
        int pass_30days= cost[2] + dp[newIndex];

        dp[index]= min(pass_1days, min(pass_7days, pass_30days));   
    }

    return dp[0];
}

// 4. Space Optimized
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    queue<pair<int, int>> weekly;
    queue<pair<int, int>> monthly;

    int ans= 0;
    for(int& day: days) {
    // 1. Remove expired days
        while(!weekly.empty() && weekly.front().first <= day - 7)
            weekly.pop();
        while(!monthly.empty() && monthly.front().first <= day - 30)
            monthly.pop();
    // 2. Add current day
        weekly.push({day, ans + cost[1]});
        monthly.push({day, ans + cost[2]});
    // 3. find min
        ans= min(ans + cost[0], min(weekly.front().second, monthly.front().second));
    }

    return ans;
}

