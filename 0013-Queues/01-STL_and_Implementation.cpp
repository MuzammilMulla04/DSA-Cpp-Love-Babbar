#include <stdlib.h>

#include <iostream>
#include <queue>
using namespace std;

void queueSTL() {
    queue<int> q;

    q.push(1);
    cout << "Front: " << q.front() << endl;
    q.push(2);
    cout << "Front: " << q.front() << endl;
    q.push(3);
    cout << "Front: " << q.front() << endl;

    cout << endl
         << "Size: " << q.size() << endl
         << endl;

    q.pop();
    cout << "Front: " << q.front() << endl;
    q.pop();
    cout << "Front: " << q.front() << endl;
    q.pop();

    cout << endl;
    if (q.empty()) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Queue is not Empty!" << endl;
    }
}
void dequeSTL() {
    deque<int> q;

    q.push_front(1);
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    q.push_back(2);
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    q.push_front(3);
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    cout << endl
         << "Size: " << q.size() << endl
         << endl;

    q.pop_back();
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    q.pop_front();
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    q.pop_front();

    cout << endl;
    if (q.empty()) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Queue is not Empty!" << endl;
    }
}

class Queue {
    int *arr;
    int size;
    int head, rear;

public:
    Queue() {
        size = 10;
        arr = new int[size];
        head = 0;
        rear = 0;
    }
    // Functions
    bool isEmpty() {
        return (head == rear) ? true : false;
    }
    void enqueue(int data) {
        if (rear == size)
            return;

        arr[rear] = data;
        rear++;
    }
    int dequeue() {
        if (isEmpty())
            return -1;

        int value = arr[head];
        arr[head] = -1;
        head++;

        if (head == rear) {
            head = 0;
            rear = 0;
        }

        return value;
    }
    int front() {
        return (isEmpty()) ? -1 : arr[head];
    }
};
class CircularQueue {
    int *arr;
    int size;
    int head, rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
        head = 0;
        rear = 0;
    }
    // Functions
    bool isEmpty() {
        return (head == rear && arr[head] == -1) ? true : false;
    }
    bool enqueue(int data) {
        if (rear == head && arr[rear] != -1)
            return false;

        arr[rear] = data;
        rear = (rear + 1) % size;
    }
    int dequeue() {
        if (isEmpty())
            return -1;

        int value = arr[head];
        arr[head] = -1;
        head = (head + 1) % size;

        return value;
    }
};
class Deque {
    int *arr;
    int size;
    int front, rear;
public:
    Deque(int n) {
        size= n;
        arr= new int[size];

        front= -1;
        rear= -1;
    }
//Checks
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return (rear+1)%size == front;
    }
// Push
    bool pushFront(int x) {
        if(isFull()) {
            return false;
        } else if(isEmpty()) {
            front= 0;
            rear= 0;
        } else {
            front= (front == 0)? size-1: front-1;
        }
        arr[front]= x;

        return true;
    }
    bool pushRear(int x) {
        if(isFull()) {
            return false;
        } else if(isEmpty()) {
            front= 0;
            rear= 0;
        } else {
            rear= (rear+1)%size;
        }

        arr[rear]= x;

        return true;
    }
// Pop
    int popFront() {
        if(isEmpty()) {
            return -1;
        }

        int value= arr[front];
        arr[front]= -1;

        if(front == rear) {
            front= -1;
            rear= -1;
        } else {
            front= (front+1)%size;
        }
    
        return value;
    }
    int popRear() {
        if(isEmpty()) {
            return -1;
        }

        int value= arr[rear];
        arr[rear]= -1;

        if(front == rear) {
            front= -1;
            rear= -1;
        } else {
            rear= (rear == 0)? size-1: rear-1;
        }
        return value;
    }
// Getters
    int getFront() {
        return isEmpty()? -1: arr[front];
    }
    int getRear() {
        return isEmpty()? -1: arr[rear];
    }
};

int main() {
    system("cls");

    // queueSTL();
    // dequeSTL();

    return 0;
}