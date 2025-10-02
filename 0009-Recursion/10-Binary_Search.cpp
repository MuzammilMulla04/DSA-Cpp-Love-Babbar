#include <iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int key) {
    if(start > end)
        return false;
    int mid= start + (end-start)/2;
    if(arr[mid] == key)
        return true;
    else if(arr[mid] < key)
        return binarySearch(arr, mid+1, end, key);
    else
        return binarySearch(arr, start, mid-1, key);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    cout << "Enter Elements:-" << endl;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter key: ";
    cin >> key;
    
    if(binarySearch(arr, 0, n, key))
        cout << key << " is found!" << endl;
    else
        cout << key << " is not found!" << endl;

    cout << endl;
    return 0;
}