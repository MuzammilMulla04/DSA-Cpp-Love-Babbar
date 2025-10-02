#include<iostream>
using namespace std;

void Swap_Alternate (int array[], int size) {
    if(size%2 == 1)
        size--;
    for(int i=0; i<size; i+=2)
        swap(array[i], array[i+1]);
}

int main() {
    int size, array[10];

    cout << "Enter Size: ";
    cin >> size;

    cout << "Enter Elements: ";
    for(int i=0; i< size; i++)
        cin >> array[i];

    Swap_Alternate (array, size);
    cout << "Swapped Array is:-\n";
    for(int i=0; i< size; i++)
        cout << array[i] << " ";
}