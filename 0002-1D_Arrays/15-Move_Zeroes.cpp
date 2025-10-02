#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void moveZeroes(int arr[], int n) {
    for(int i=0, j=0; j<n; j++) {
        if(arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main() {
    system("cls");

    int arr[]= { 0, 0, 3, 6, 9};
    int n= sizeof(arr)/sizeof(int);

    moveZeroes(arr, n);
    print(arr, n);


    cout << endl;
    return 0;
}