#include<iostream>
#include<queue>
using namespace std;

int main() {
    system("cls");


//max heap
    priority_queue<int> max_heap;

    max_heap.push(5);
    max_heap.push(1);
    max_heap.push(4);
    max_heap.push(3);
    max_heap.push(2);

    for(int i=0, size=max_heap.size(); i<size; i++) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;
    cout << " Is max_heap Empty? : " << max_heap.empty() << endl;

//min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(5);
    min_heap.push(1);
    min_heap.push(4);
    min_heap.push(3);
    min_heap.push(2);

    for(int i=0, size=min_heap.size(); i<size; i++) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;
    cout << " Is min_heap Empty? : " << min_heap.empty() << endl;

    return 0;
}