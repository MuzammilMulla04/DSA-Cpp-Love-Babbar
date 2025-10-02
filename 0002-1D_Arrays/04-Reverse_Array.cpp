#include<iostream>
using namespace std;

void Reverse_Array (int array[], int size) {
    for(int start=0, end=size-1; start<end; start++, end--)
        swap(array[start], array[end]);
}

int main() {
    int size, array[10], key;

    cout << "Enter Size: ";
    cin >> size;

    cout << "Enter Elements: ";
    for(int i=0; i< size; i++)
        cin >> array[i];

    Reverse_Array(array, size);
    cout << "Reverse Array is:-\n";
    for(int i=0; i< size; i++)
        cout << array[i] << " ";

}