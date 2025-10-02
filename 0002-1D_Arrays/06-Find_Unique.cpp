#include<iostream>
using namespace std;

int Find_Unique (int array[], int size) {
    int ans=0;
    for(int i=0; i<size; i++)
        ans=ans^array[i];
    return ans;
}

int main() {
    int size, array[100];

    cout << "Enter Size: ";
    cin >> size;

    cout << "Enter Elements: ";
    for(int i=0; i< size; i++)
        cin >> array[i];

    cout << "\nUnique Element is: " << Find_Unique (array, size);

}