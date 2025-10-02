#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(int n, vector<int>& quantities, int dist) {
        int store= 0;
        for(int& q: quantities) {
            store += (q+dist-1)/dist;
            if(store > n)
                return false;
        }
        return store <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxQ= INT_MIN;
        for(int& quantity: quantities)
            maxQ= max(maxQ, quantity);

        int start= 1, end= maxQ;
        while(start < end) {
            int mid= start + (end-start)/2;

            if(isPossible(n, quantities, mid))
                end= mid;
            else
                start= mid+1;
        }
        return end;
    }
};