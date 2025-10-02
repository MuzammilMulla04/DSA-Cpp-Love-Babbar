#include <bits/stdc++.h>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    int mod= 1e9 + 7;

    long long tempSum= 0;
    for(int i=0; i<n; i++)
        tempSum= (tempSum + arr[i]) % mod;

    vector<int> ans;
    for(auto& query: queries) {
        int start= (query[0] % n) - 1;
        int loops= (query[1] - query[0]) / n;
        int end= (query[1] % n) - 1;

        long long sum= 0;

        for(int i= start; i<n; i++) {
            sum= (sum+arr[i]) % mod;
        }
        sum += (loops * tempSum) % mod;
        for(int i= 0; i<=end; i++) {
            sum= (sum+arr[i]) % mod;
        }

        ans.push_back(sum%mod);
    }

    return ans;
}