#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int start, int end) {
    if(start >= end)
        return start;

    int mid= start+ (end-start)/2;
    if(arr[mid] < arr[mid+1])
        return solve(arr, mid+1, end);
    else
        return solve(arr, start, mid);
}
int findPeakElement(vector<int>& arr) {
    return arr[solve(arr, 0, arr.size()-1)];
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
    
    sort(arr.begin(), arr.end());

    cout << "Peak Element: " << findPeakElement(arr) << endl;
    
    cout << endl;
    return 0;
}