#include<iostream>
using namespace std;

bool uniqueNoOfOccurences(int arr[], int n) {
    int maxi = arr[0];
    int mini= arr[0];
    for(int i=1; i<n; i++) {
        maxi= max(maxi, arr[i]);
        mini= min(mini, arr[i]);
    }

    int diff = maxi-mini+1;
    int freq[diff] = { 0 };
    for(int i=0; i<n; i++) {
        freq[arr[i]-mini]++;
    }

    for(int i=0; i<diff; i++) {
        if(freq[i] != 0)
            cout << i+mini << " -> " << freq[i] << endl;
    }

    bool isUnique = true;
    for(int i=0, j=diff; i != j; i++) {
        int a= freq[i-mini], b= freq[j-mini];
        
        if(a&b && a==b) {
            isUnique= false;
            break;
        }
    }
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    int arr[n];
    cout << "Enter Elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    
    if(uniqueNoOfOccurences(arr, n))
        cout << "Unique" << endl;
    else
        cout << "Not Unique" << endl;
    cout << endl;
    return 0;
}