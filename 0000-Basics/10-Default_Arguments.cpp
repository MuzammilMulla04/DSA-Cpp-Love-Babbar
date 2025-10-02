#include <iostream>
using namespace std;

void print(int arr[], int n, int start= 0) {
    for(int i=start; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    system("cls");

    int arr[5] = {1, 2, 3, 4, 5};
    
    print(arr, 5);
    print(arr, 5, 2);

    cout << endl;
    return 0;
}