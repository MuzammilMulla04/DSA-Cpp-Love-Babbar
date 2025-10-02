#include<iostream>
#include<array>
using namespace std;

int main() {
    system("cls");

    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Size of array: " << arr.size() << endl;
    cout << "Element at position 2 of array: " << arr.at(2) << endl;
    cout << "Element at front of array: " << arr.front() << endl;
    cout << "Element at back of array: " << arr.back() << endl;
    cout << "Address of array(index 0): " << arr.data() << endl;
    cout << "Is array empty: " << arr.empty() << endl;
    cout << "Max size of array: " << arr.max_size() << endl;
    
    system("pause>0");
    cout << endl;
    return 0;
}