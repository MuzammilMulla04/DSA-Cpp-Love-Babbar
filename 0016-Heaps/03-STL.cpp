#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

// Max-Heap
void maxHeap() {
    priority_queue<int> h;

    h.push(10);
    h.push(20);
    h.push(30);
    h.push(40);
    h.push(50);

    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;
    
    h.pop();
    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;

    h.pop();
    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;

    if(h.empty())
        cout << "Heap is Empty!" << endl;
    else
        cout << "Heap is not Empty!" << endl;

    h.pop();
    h.pop();
    h.pop();

    if(h.empty())
        cout << "Heap is Empty!" << endl;
    else
        cout << "Heap is not Empty!" << endl;
}
// Min-Heap
void minHeap() {
    priority_queue<int, vector<int>, greater<int>> h;

    h.push(10);
    h.push(20);
    h.push(30);
    h.push(40);
    h.push(50);

    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;
    
    h.pop();
    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;

    h.pop();
    cout << "Top: " << h.top() << endl;
    cout << "Size: " << h.size() << endl;

    if(h.empty())
        cout << "Heap is Empty!" << endl;
    else
        cout << "Heap is not Empty!" << endl;

    h.pop();
    h.pop();
    h.pop();

    if(h.empty())
        cout << "Heap is Empty!" << endl;
    else
        cout << "Heap is not Empty!" << endl;
}

int main() {
    system("cls");

    cout << endl << "Max-Heap:-" << endl;
    maxHeap();
    cout << endl << "Min-Heap:-" << endl;
    minHeap();

    return 0;
}