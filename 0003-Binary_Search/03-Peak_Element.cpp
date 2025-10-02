#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int beg=0, end= arr.size() -1;
    while (beg <= end) {
        int mid= beg + (end-beg)/2;

        if(arr[mid] < arr[mid+1])
            beg= mid+1;
        else
            end= mid;
    }
    return beg;
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