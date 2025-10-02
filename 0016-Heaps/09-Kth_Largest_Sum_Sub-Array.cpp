#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k) {
    int n= arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++) {
        int sum= 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            
            if(minHeap.size() < k) {
                minHeap.push(sum);
            } else {
                if(minHeap.top() < sum) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
}
