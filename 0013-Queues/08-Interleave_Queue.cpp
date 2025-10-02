#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q) {
        int n= q.size();
        stack<int> s;
    // Push 1st half 1st time
        for(int i=0; i<n/2; i++) {
            int temp= q.front();
            q.pop();
            s.push(temp);
        }
    // pop stack into queue
        while(!s.empty()) {
            int temp= s.top();
            s.pop();
            q.push(temp);
        }
    //Put second half behind
        for(int i=0; i<n/2; i++) {
            int temp= q.front();
            q.pop();
            q.push(temp);
        }
    // Push 1st half 2nd time
        for(int i=0; i<n/2; i++) {
            int temp= q.front();
            q.pop();
            s.push(temp);
        }
    //Now Interleave
        while(!s.empty()) {
            int temp= s.top();
            s.pop();
            q.push(temp);

            temp= q.front();
            q.pop();
            q.push(temp);
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            int temp= q.front();
            q.pop();

            ans[i]= temp;
        }

        return ans;
    }
};
