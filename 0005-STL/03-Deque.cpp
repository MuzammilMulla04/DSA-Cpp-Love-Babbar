#include<iostream>
#include<deque>
using namespace std;

int main() {
    system("cls");

    deque<int> d;

    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_front(2);
    d.push_front(1);

    cout << "Deque: ";
    for(int i:d)
        cout << i << " ";
    cout << endl;

    cout << "Size: " << d.size() << endl;
    cout << "Max size: " << d.max_size() << endl;

    cout << endl;
    
    d.pop_back();
    d.pop_front();

    cout << "Deque now: ";
    for(int i:d)
        cout << i << " ";
    cout << endl;

    cout << "Size now: " << d.size() << endl;
    
    cout << endl;

    cout << "Front element: " << d.front() << endl;
    cout << "Element at index 1: " << d.at(1) << endl;
    cout << "Back element: " << d.back() << endl;

    cout << endl;

    d.erase(d.begin(), d.end());    // erase [start,end) elements

    cout << "Size: " << d.size() << endl;
    cout << "Is empty: " << d.empty() << endl;

    cout << endl;
    return 0;
}