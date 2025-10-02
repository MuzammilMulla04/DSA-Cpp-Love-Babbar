#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    if(n < 1)    
        return;

    int temp= arr[n-1], i;
    for(i=n-2; i>=0; i--) {
        if(arr[i] > temp)
            arr[i+1]= arr[i];
        else
            break;
    }
    arr[i+1]= temp;

    insertionSort(arr+1, n-1);
}

int main() {
    system("cls");

    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << endl;
    return 0;
}