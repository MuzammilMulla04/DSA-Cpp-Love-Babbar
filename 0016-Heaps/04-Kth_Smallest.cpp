#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> h;

        for(int i=0; i<k; i++)
            h.push(arr[i]);

        for(int i=k; i<=r; i++) {
            if(arr[i] < h.top()) {
                h.pop();
                h.push(arr[i]);
            }
        }

        return h.top();
    }
};
