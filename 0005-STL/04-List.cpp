#include<iostream>
#include<list>
using namespace std;

int main() {
    system("cls");

    list<int> l;

    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_front(2);
    l.push_front(1);

    cout << "List: ";
    for(int i:l)
        cout << i << " ";
    cout << endl;
    
    cout << "Size: " << l.size() << endl;

    l.erase(l.begin());    // erase [start,end) elements
    for(int i:l)
        cout << i << " ";
    cout << endl;


    cout << endl;
    list<int> a(5, 100);    // 5 elements with value 100
    cout << "List a: ";
    for(int i:a)
        cout << i << " ";

    cout << endl;
    return 0;
}