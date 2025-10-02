#include<iostream>
using namespace std;

bool linear_search(int array[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(array[i] == key)
            return true;
    }
    return false;
}

int main() {
    system("cls");
    
    int size, array[10], key;

    cout << "Enter Size: ";
    cin >> size;

    cout << "Enter Elements: ";
    for(int i=0; i< size; i++)
        cin >> array[i];

    cout << "Enter Key: ";
    cin >> key;

    bool found= linear_search(array, size, key);
    if(found)
         cout << endl << key << " is present";
    else
         cout << endl << key << " is absent";

    system("pause>0");
}