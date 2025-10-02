#include<bits/stdc++.h>
using namespace std;

class Solution {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    vector<double> getMedian(vector<int>& arr) {
        int n= arr.size();
        vector<double> median(n);
        
        for(int i=0; i<n; ++i) {
            if(maxHeap.empty() || arr[i] <= maxHeap.top()) {
                maxHeap.push(arr[i]);
            } else {
                minHeap.push(arr[i]);
            }
            
            while(!minHeap.empty() && minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            while(!maxHeap.empty() && maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            
            if(maxHeap.size() == minHeap.size()) {
                median[i]= (maxHeap.top() + minHeap.top()) / 2.0;
            } else if(maxHeap.size() > minHeap.size()) {
                median[i]= maxHeap.top();
            } else {
                median[i]= minHeap.top();
            }
        }
        
        return median;
    }
};