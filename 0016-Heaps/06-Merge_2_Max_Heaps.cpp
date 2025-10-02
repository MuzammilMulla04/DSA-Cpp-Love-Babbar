#include <bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(vector<int>& h, int& size, int index) {
        if(size == 0)
            return;

        int largest= index;
        int leftIndex= 2*index+1;
        int rightIndex= 2*index+2;

        if(leftIndex < size && h[leftIndex] > h[largest])
            largest= leftIndex;
        if(rightIndex < size && h[rightIndex] > h[largest])
            largest= rightIndex;

        if(largest == index)
            return;
        else {
            swap(h[largest], h[index]);
            heapify(h, size, largest);
        }
    }
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans(n+m);

        for(int i=0; i<n; i++)
            ans[i]= a[i];
        for(int i=0; i<m; i++)
            ans[i+n]= b[i];

        int size= n+m;
        for(int i=(size-1)/2; i>=0; i--)
            heapify(ans, size, i);
        
        return ans;
    }
};
