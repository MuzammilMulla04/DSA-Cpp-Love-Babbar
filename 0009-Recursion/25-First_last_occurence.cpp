#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& arr, int start, int end, int key, int ansIndex= -1) {
    if(start > end) {
        return ansIndex;
    }
    int mid= start+ (end-start)/2;
    if(arr[mid] == key) {
        ansIndex= mid;
        return firstOccurence(arr, start, mid-1, key, ansIndex);
    }

    if(arr[mid] < key)
        return firstOccurence(arr, mid+1, end, key, ansIndex);
    else
        return firstOccurence(arr, start, mid-1, key, ansIndex);
}
int lastOccurence(vector<int>& arr, int start, int end, int key, int ansIndex= -1) {
    if(start > end)
        return ansIndex;
    
    int mid= start+ (end-start)/2;
    if(arr[mid] == key) {
        ansIndex= mid;
        return lastOccurence(arr, mid+1, end, key, ansIndex);
    }

    if(arr[mid] < key)
        return lastOccurence(arr, mid+1, end, key, ansIndex);
    else
        return lastOccurence(arr, start, mid-1, key, ansIndex);
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

    int key;
    cout << "Enter Key: ";
    cin >> key;

    int FirstOccurence= firstOccurence(arr, 0, n-1, key);
    int LastOccurence= lastOccurence(arr, 0, n-1, key);

    cout << "First Occurence: " << FirstOccurence << endl;
    cout << "Last Occurence: " << LastOccurence << endl;
    
    cout << endl;
    return 0;
}