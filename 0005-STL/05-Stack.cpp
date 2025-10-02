#include<iostream>
#include<stack>
using namespace std;

int main() {
    system("cls");

    stack<int> s;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    cout << "Top Element: " << s.top() << endl;

    s.pop();
    cout << "Top Element: " << s.top() << endl;

    cout << "Size: " << s.size() << endl;
    cout << "Is Empty: " << s.empty() << endl;


    cout << endl;
    return 0;
}