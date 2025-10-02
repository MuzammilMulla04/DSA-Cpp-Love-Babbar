#include<bits/stdc++.h>
using namespace std;

class Solution {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n= arr.size();
        
        for(int i=0; i<k; ++i)
            minHeap.push(arr[i]);
        for(int i=k; i<n; ++i) {
            minHeap.push(arr[i]);
            minHeap.pop();
        }
        
        vector<int> ans(k);
        int i= k-1;
        while(!minHeap.empty()) {
            ans[i]= minHeap.top();
            minHeap.pop();
            --i;
        }
        
        return ans;
    }
};
