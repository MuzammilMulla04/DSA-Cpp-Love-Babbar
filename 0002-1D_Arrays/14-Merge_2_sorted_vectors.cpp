#include<iostream>
#include <vector>
using namespace std;

void ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i=m-1, j=n-1, index=m+n-1;

    while(i >= 0 && j >= 0) {
        if(arr1[i] > arr2[j])
            arr1[index--]= arr1[i--];
        else
            arr1[index--]= arr2[j--];
    }

    while(j >= 0)
        arr1[index--]= arr2[j--];
}

int main() {
    system("cls");

    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    vector<int> arr1(m+n);
    cout << "Enter Elements of arr1: ";
    for(int i=0; i<m+n; i++)
        cin >> arr1[i];

    cout << "Enter Elements of arr2: ";
    vector<int>arr2(n);
    for(int i=0; i<n; i++)
        cin >> arr2[i];

    ninjaAndSortedArrays(arr1, arr2, m, n);

    for(auto i:arr1)
        cout << i << " ";
    cout << endl;
    
    cout << endl;
    return 0;
}