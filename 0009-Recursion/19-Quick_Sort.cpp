#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot= arr[start];
    
    int smallerThanPivotCount=0;
    for(int i=start+1; i <= end; i++) {
        if(arr[i] <= pivot)
            smallerThanPivotCount++;
    }
// Placing pivot to right position
    int pivotIndex= start+smallerThanPivotCount;
    swap(arr[start], arr[pivotIndex]);

//Sorting left and right parts of pivot
    while(start < pivotIndex && end > pivotIndex) {
        while (arr[start] < pivot) {
            start++;
        }
        while (arr[start] > pivot) {
            end--;
        }
        if(start < pivotIndex && end > pivotIndex) {
            swap(arr[start++], arr[end--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end) {
    if(start >= end)
        return ;
// Place pivot in correct position
    int pivotIndex= partition(arr, start, end);

//Sorting left-part
    quickSort(arr, start, pivotIndex-1);
//Sorting right-part
    quickSort(arr, pivotIndex+1, end);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    int* arr= new int[n];

    cout << "Enter Elements:-" << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << endl;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete []arr;

    cout << endl;
    return 0;
}