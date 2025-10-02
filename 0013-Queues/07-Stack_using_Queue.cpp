#include <bits/stdc++.h>
using namespace std;

class stackByQueue {
    queue<int> q;
public:
    void pushFront(int value) {
        q.push(value);
        for(int i= q.size()-1; i>0; i--) {
            int temp= q.front();
            q.pop();
            q.push(temp);
        }
    }
    void popFront() {
        q.pop();
    }
    int top() {
        return q.front();
    }
    int size() {
        return q.size();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    system("cls");

    stackByQueue sq;

    sq.pushFront(1);
    cout << "Top: " << sq.top() << endl;
    sq.pushFront(2);
    cout << "Top: " << sq.top() << endl;
    sq.pushFront(3);
    cout << "Top: " << sq.top() << endl;

    cout << "Size: " << sq.size() << endl;

    sq.popFront();
    cout << "Top: " << sq.top() << endl;
    sq.popFront();
    cout << "Top: " << sq.top() << endl;
    sq.popFront();

    if(sq.empty()) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Stack is not Empty!" << endl;
    }

    return 0;
}
