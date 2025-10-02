#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key) {
    if(size == 0)
        return false;
    if(arr[0] == key)
        return true;
    return linearSearch(arr+1, size-1, key);
}

int main() {
    system("cls");

    int arr[]= {3, 5, 1, 2, 6};
    int size= sizeof(arr)/ sizeof(int);
    int key= 2;

    if(linearSearch(arr, size, key))
        cout << key << " is found!" << endl;
    else
        cout << key << " is not found!" << endl;

    cout << endl;
    return 0;
}