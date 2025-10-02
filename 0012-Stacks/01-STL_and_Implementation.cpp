#include<iostream>
#include<stack>
using namespace std;
//STL
void stl() {
    stack<int> s;
    s.push(2);
    s.push(3);

    s.pop();

    cout << "Top: " << s.top() << endl;

    if(s.empty())
        cout << "Stack is Empty!" << endl;
    else
        cout << "Stack is not Empty!" << endl;

    cout << "Size: " << s.size() << endl;
}

// Implementation
/* 1. Array
class StackArray {
    int size, top, *arr;
public:
//Constructor & Destructor
    StackArray(const int& n): size(n), top(-1), arr(new int[size]) {}
    ~StackArray() { delete []arr; }
// Checks
    bool isFull() {
        return top == size;
    }
    bool isEmpty() {
        return top == -1;
    }
// Operations
    void push(const int& value) {
        if(isFull()) {
            cout << "Stack Overflowed!" << endl;
            return;
        }
        arr[++top]= value;
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflowed!" << endl;
            return;
        }
        top--;
    }
    int top() {
        return !isEmpty()? arr[top]: -1;
    }
};
 */

// 2. Linked-List
class Node {
public:
    int data;
    Node* next;
// Constructor & Destructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << this->data << " is deleted!" << endl;
        if (this->next != NULL) {
            this->next = NULL;
            delete this->next;
        }
    }
};
class Stack {
    Node* head;
public:
    Stack(): head(nullptr) {}
    ~Stack() {
        if(head != NULL) {
            delete head->next;
        }
    }
// Checks
    bool isEmpty() { return head == nullptr; }
// Operations
    void push(const int& value) {
        Node* newNode= new Node(value);
        if(isEmpty()) {
            head= newNode;
        } else {
            newNode->next= head;
            head= newNode;
        }
    }
    void pop() {
        if(isEmpty()) {
            return;
        } else {
            Node* temp= head;
            head= head->next;
            delete temp;
        }
    }
    int top() {
        if(isEmpty()) {
            return -1;
        } else {
            return head->data;
        }
    }
};

int main() {
    system("cls");

// STL
    // stl();

// Implementation
    // StackArray s(5);
    Stack s;

    s.push(22);
    s.push(43);
    s.push(44);

    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    return 0;
}