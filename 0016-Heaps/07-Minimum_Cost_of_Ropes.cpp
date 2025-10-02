#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for(int i=0; i<n; i++)
            minHeap.push(arr[i]);

        long long cost= 0;
        while(minHeap.size() != 1) {
            long long val1= minHeap.top();
            minHeap.pop();
            long long val2= minHeap.top();
            minHeap.pop();

            long long sum= val1 + val2;
            minHeap.push(sum);

            cost += sum;
        }

        return cost;
    }
};
