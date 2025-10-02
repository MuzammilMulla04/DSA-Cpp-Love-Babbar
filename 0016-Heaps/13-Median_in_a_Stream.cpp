#include <bits/stdc++.h>
using namespace std;

int signum(int num1, int num2) {
    return (num1 > num2) - (num1 < num2);
}
void getMedian(int element, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int& median) {
    switch(signum(maxHeap.size(), minHeap.size())) {
        case 0:
            if(element < median) {
                maxHeap.push(element);
                median= maxHeap.top();
            } else {
                minHeap.push(element);
                median= minHeap.top();
            }
            return;
        case 1:
            if(element < median) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            } else {
                minHeap.push(element);
            }
            break;
        case -1:
            if(element < median) {
                maxHeap.push(element);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
            }
            break;
    }

    median= maxHeap.top() + minHeap.top();
    median /= 2;
}
vector<int> findMedian(vector<int> &arr, int n) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> ans;
    int median= INT_MAX;

    for(int i=0; i<n; i++) {
        int element= arr[i];

        getMedian(element, maxHeap, minHeap, median);

        ans.push_back(median);
    }

    return ans;
}
