#include<iostream>
using namespace std;

void Pair_Sum(int arr[], int size, int S) {
    int brr[size], k=0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++) {
            if(arr[i]+arr[j]== S) {
                brr[k++]= min(arr[i], arr[j]);
                brr[k++]= max(arr[i], arr[j]);
            }
        }
    }
    cout << "\nPairs are:-\n";
    for(int i=0; i<k; i++) {
        cout << brr[i] << " ";
        if(i%2)
        	cout << endl;
    }
}

int main() {
    int arr[]= { 2, -3, 3, 3, -2 };
    int size= 5;
    int S= 0;

    Pair_Sum(arr, size, S);
    return 0;
}