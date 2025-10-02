#include<iostream>
#include<queue>
using namespace std;

int main() {
    system("cls");

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Front Element: " << q.front() << endl;
    cout << "Back Element: " << q.back() << endl;

    cout << "Size: " << q.size() << endl;
    q.pop();
    cout << "Front Element now: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.empty() << endl;


    cout << endl;
    return 0;
}