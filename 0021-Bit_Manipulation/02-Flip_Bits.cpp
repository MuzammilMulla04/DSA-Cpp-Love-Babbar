#include <bits/stdc++.h>
using namespace std;

int flipBits(int* arr, int n) {
    int oneCount= 0;
    int maxOnes= 0, currOnes= 0;
    for(int i=0; i<n; i++) {
        oneCount += arr[i];
        currOnes += arr[i] == 1? -1: 1;

        maxOnes= max(currOnes, maxOnes);
        if(currOnes < 0)
            currOnes= 0;
    }

    return oneCount+maxOnes;
}

int main() {
    system("cls");

    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr= new int[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Possible 1's: " << flipBits(arr, n) << endl;
    return 0;
}