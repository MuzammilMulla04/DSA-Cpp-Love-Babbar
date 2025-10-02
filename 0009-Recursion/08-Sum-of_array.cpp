#include <iostream>
using namespace std;

int getSum(int *arr, int size) {
    if(size == 0)
        return 0;
    return arr[0] + getSum(arr+1, size-1);
}

int main() {
    system("cls");

    int arr[]= {2, 4, 9, 9, 9};
    int size= sizeof(arr)/ sizeof(int);
    cout << "Sum: " << getSum(arr, size) << endl;

    cout << endl;
    return 0;
}