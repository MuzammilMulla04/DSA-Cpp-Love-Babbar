#include<iostream>
#include<vector>
using namespace std;

int main() {
    system("cls");

    vector<int> v;
    cout << "Size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
 
    cout << endl;

    v.push_back(1);
    cout << "Size after adding 1: " << v.size() << endl;
    cout << "capacity after adding 1: " << v.capacity() << endl;
    v.push_back(2);
    cout << "Size after adding 2: " << v.size() << endl;
    cout << "capacity after adding 2: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Size after adding 3: " << v.size() << endl;
    cout << "capacity after adding 3: " << v.capacity() << endl;
    v.push_back(4);
    cout << "Size after adding 4: " << v.size() << endl;
    cout << "capacity after adding 4: " << v.capacity() << endl;
    v.push_back(5);
    cout << "Size after adding 5: " << v.size() << endl;
    cout << "capacity after adding 5: " << v.capacity() << endl;
 
    cout << endl;

    cout << "Element at index 2: " << v.at(2) << endl;
    cout << "Element at Front: " << v.front() << endl;
    cout << "Element at Back: " << v.back() << endl;

    cout << endl;

    cout << "Before pop_back: " << endl;
    for(int i:v)
        cout << i << " ";
    cout << endl;
    v.pop_back();
    cout << "After pop_back: " << endl;
    for(int i:v)
        cout << i << " ";
    cout << endl;

    cout << endl;

    cout << "Size before clearing: " << v.size() << endl;
    cout << "Capacity before clearing: " << v.capacity() << endl;
    v.clear();
    cout << "Size after clearing: " << v.size() << endl;
    cout << "Capacity after clearing: " << v.capacity() << endl;

    cout << endl;
    vector<int> a(5, 1); // 5 elements with intialized value as 1
    cout << "Printing a: " << endl;
    for(int i:a)
        cout << i << " ";
    cout << endl;
   
    cout << endl;

    vector<int> b(a); // copy of vector a
    cout << "Printing b: " << endl;
    for(int i:b)
        cout << i << " ";
    cout << endl;

    cout << endl;
    return 0;
}