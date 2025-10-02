#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    if(n == 0 || n == 1)
        return ;
    int min=0;
    for(int i=0; i<n; i++) {
        if(arr[min] > arr[i])
            min= i;
    }
    swap(arr[0], arr[min]);
    return selectionSort(arr+1, n-1);
}

int main() {
    system("cls");

    int arr[]= {5, 4, 3, 2, 1};
    int n= sizeof(arr)/ sizeof(int);

    selectionSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << endl;
    return 0;
}