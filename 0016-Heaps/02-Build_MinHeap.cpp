#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int size, int index) {
    if(size == 0)
        return;

    int smallest= index;
    int leftIndex= 2*index + 1;
    int rightIndex= 2*index + 2;

    if(leftIndex < size && arr[leftIndex] < arr[smallest]) {
        smallest= leftIndex;
    }
    if(rightIndex < size && arr[rightIndex] < arr[smallest]) {
        smallest= rightIndex;
    }

    if(smallest != index) {
        swap(arr[smallest], arr[index]);
        heapify(arr, size, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr) {
    int n= arr.size();
    for(int i= n/2 - 1; i>=0; i--)
        heapify(arr, n, i);
    return arr;
}
