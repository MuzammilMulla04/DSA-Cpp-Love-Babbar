#include <bits/stdc++.h> 
using namespace std;

// Using Sort
vector<int> Klargest1(vector<int> &arr, int k, int n) {
    for(int i=0; i<k; i++){
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i])
                swap(arr[i], arr[j]);
        }
    }
    vector<int> ans(k);
    for(int i=k-1; i>=0; i--)
        ans[k-1-i]= arr[i];   
    
    return ans;
}
// Using minHeap
vector<int> Klargest2(vector<int> &arr, int k, int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++) {
        if(minHeap.size() < k) {
            minHeap.push(arr[i]);
        } else if(minHeap.top() < arr[i]) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    vector<int> ans;
    while(!minHeap.empty()) {
        int top= minHeap.top();
        minHeap.pop();

        ans.push_back(top);
    }

    return ans;
}
// Using QuickSelect
int partition(vector<int>& arr, int start, int end) {
    int pivotValue = arr[start];
    int count = 0;

    // Count elements smaller than the pivotValue
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivotValue) {
            count++;
        }
    }

    // Place the pivot at the correct position
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    // Arrange elements around the pivot
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivotValue) {
            i++;
        }
        while (arr[j] >= pivotValue) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}
void quickSelect(vector<int>& arr, int start, int end, int k) {
    if (start < end) {
        int pivot = partition(arr, start, end);

        // If pivot is k, we found the k-th largest element
        if (pivot == k) {
            return;
        } else if (pivot < k) {
            quickSelect(arr, pivot + 1, end, k);
        } else {
            quickSelect(arr, start, pivot - 1, k);
        }
    }
}

vector<int> Klargest3(vector<int> &arr, int k, int n) {
    // Find the (n - k)th element in 0-based index to partition array
    quickSelect(arr, 0, n - 1, n - k);

    // Collect the k largest elements
    vector<int> ans(arr.end() - k, arr.end());
    
    // Sort the k largest elements in ascending order
    sort(ans.begin(), ans.end());
    
    return ans;
}