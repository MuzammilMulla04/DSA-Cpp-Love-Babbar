#include<bits/stdc++.h>
using namespace std;

class QueueByStack {
    stack<int> s;
public:
    void pushBack(int value) {
        if(s.empty()) {
            s.push(value);
            return;
        }

        int temp= s.top();
        s.pop();

        pushBack(value);
        s.push(temp);
    }
    void popFront() {
        if(s.empty())
            return;
        s.pop();
    }
    int front() {
        return s.empty()? -1: s.top();
    }
    int size() {
        return s.size();
    }
    bool empty() {
        return s.empty();
    }
};

int main() {
    system("cls");

    QueueByStack qs;

    qs.pushBack(1);
    cout << "Front: " << qs.front() << endl;
    qs.pushBack(2);
    cout << "Front: " << qs.front() << endl;
    qs.pushBack(3);
    cout << "Front: " << qs.front() << endl;

    cout << "Size: " << qs.size() << endl;

    qs.popFront();
    cout << "Front: " << qs.front() << endl;
    qs.popFront();
    cout << "Front: " << qs.front() << endl;
    qs.popFront();

    if(qs.empty()) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Queue is not Empty!" << endl;
    }

    return 0;
}
