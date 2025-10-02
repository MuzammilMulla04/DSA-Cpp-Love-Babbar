#include <iostream>
using namespace std;

bool isArraySorted(int *arr, int size) {
    if(size <= 1)
        return true;
    if(arr[0] > arr[1])
        return false;
    return isArraySorted(arr+1, size-1);
}

int main() {
    system("cls");

    int arr[]= {2, 4, 5, 9, 11, 13};
    int size= sizeof(arr)/ sizeof(int);
    if(isArraySorted(arr, size))
        cout << "Array is Sorted!" << endl;
    else
        cout << "Array is not Sorted!" << endl;

    cout << endl;
    return 0;
}