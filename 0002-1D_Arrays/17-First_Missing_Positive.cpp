#include <bits/stdc++.h> 
using namespace std;

int firstMissing(int arr[], int n) {
    int minElement= INT_MAX;
    int maxElement= INT_MIN;

//Getting Max & Min elements
    for(int i=0; i<n; i++) {
        if(arr[i] >= 0) {
            minElement= min(minElement, arr[i]);
            maxElement= max(maxElement, arr[i]);
        }
    }
// Marking if Present
    int size= maxElement-minElement+1;
    vector<bool> isPresent(size, false);
    for(int i=0; i<n; i++) {
        if(arr[i] >= 0)
            isPresent[arr[i]]= true;
    }
//Check missing number
//Case 1
    for(int i=1; i<size; i++) {
        if(!isPresent[i])
            return i;
    }
//Case 2
    return maxElement+1;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    int *arr= new int[n];
    cout << "Enter Elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int ans= firstMissing(arr, n);
    cout << "Ans: " << ans << endl;

    cout << endl;
    return 0;
}