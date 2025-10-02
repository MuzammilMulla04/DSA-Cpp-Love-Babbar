#include <bits/stdc++.h>
using namespace std;

// 4. Space Optimized
int maximumNonAdjacentSum(vector<int>& money, int start, int end) {
    vector<long long int> dp(3, 0);
    
    for(int i= start; i <= end; i++) {
        dp[2]= max(dp[1], dp[0] + money[i]);

        dp[0]= dp[1];
        dp[1]= dp[2];
    }

    return dp[2];
}
long long int houseRobber(vector<int>& money) {
    int n= money.size();

    if(n == 1)
        return money[0];
 
    long long int ans1= maximumNonAdjacentSum(money, 0, n-2);
    long long int ans2= maximumNonAdjacentSum(money, 1, n-1);

    return max(ans1, ans2);
}