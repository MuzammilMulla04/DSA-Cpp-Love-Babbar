#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& arr, int start, int end) {
    if(start >= end)
        return start;
    
    int mid= start+ (end-start)/2;
    if(arr[mid] > arr[0])
        return findPivot(arr, start, mid);
    else
        return findPivot(arr, mid+1, end);
}
bool binarySearch(vector<int>& arr, int start, int end, int key) {
    if(start > end)
        return false;

    int mid= start+ (end-start)/2;
    if(arr[mid] == key)
        return true;
    else if(arr[mid] < key)
        return binarySearch(arr, mid+1, end, key);
    else
        return binarySearch(arr, start, mid-1, key);
}
bool searchPivotSortedArray(vector<int> & arr, int key) {
    int start=0, end= arr.size()-1, pivotIndex= findPivot(arr, start, end);
    if(arr[0] > key)
        return binarySearch(arr, findPivot(arr, start, end), end, key);
    else
        return binarySearch(arr, start, findPivot(arr, start, end)-1, key);
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter Elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter Key: ";
    cin >> key;

    if(searchPivotSortedArray(arr, key))
        cout << key << " is Present!" << endl;
    else
        cout << key << " is not Present!" << endl;
       
    cout << endl;
    return 0;
}