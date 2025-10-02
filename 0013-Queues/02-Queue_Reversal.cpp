#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(queue<int>& q) {
        if(q.empty())
            return;
        
        int temp= q.front();
        q.pop();

        solve(q);
        
        q.push(temp);
    }
public:
    queue<int> rev(queue<int> q) {
        if(q.empty())
            return q;

        solve(q);
        return q;
    }
};
