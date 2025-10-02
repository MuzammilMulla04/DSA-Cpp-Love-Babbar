#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int endIndex, vector<int>& ans, stack<int>& s) {
// Base Case
    if(endIndex < 0) {
        return;
    }

// Solve 1 Case
    if(arr[endIndex] >= s.top()) {
        ans[endIndex]= s.top();
        s.push(arr[endIndex]);
        solve(arr, endIndex-1, ans, s);
    } else {
// Recursive Call
        s.pop();
        solve(arr, endIndex, ans, s);
    }
}
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    solve(arr, n-1, ans, s);
    return ans;
}