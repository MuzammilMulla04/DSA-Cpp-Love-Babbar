#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        for(int i=0; i<n; i++) {
            s.push(i);
        }

        while(s.size() > 1) {
            int a= s.top();
            s.pop();
            int b= s.top();
            s.pop();

            if(M[a][b]) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int candidate= s.top();
        int zeroCount= 0, oneCount= 0;
        for(int i=0; i<n; i++) {
            zeroCount= M[candidate][i] == 0 ? zeroCount+1: zeroCount;
            oneCount= M[i][candidate] == 1 ? oneCount+1: oneCount;
        }

        if(zeroCount == n && oneCount == n-1) {
            return candidate;
        } else {
            return -1;
        }
    }
};