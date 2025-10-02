#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data= data;
        this->row= row;
        this->col= col;
    }
};
class compare {
public:
    bool operator()(Node a, Node b) {
        return a.data > b.data;
    }
};
int kSorted(vector<vector<int>> &arr, int rows, int cols) {
    priority_queue<Node, vector<Node>, compare> minHeap;

    int maxInHeap= INT_MIN;
    for(int i=0; i<rows; i++) {
        minHeap.push(Node(arr[i][0], i, 0));
        maxInHeap= max(maxInHeap, arr[i][0]);
    }

    int ansRange= INT_MAX;
    while(!minHeap.empty()) {
        Node topNode= minHeap.top();
        minHeap.pop();

        int minInHeap= topNode.data;
        int row= topNode.row;
        int col= topNode.col + 1;

        ansRange= min(ansRange, maxInHeap-minInHeap);

        if(col < cols) {
            minHeap.push(Node(arr[row][col], row, col));
            maxInHeap= max(maxInHeap, arr[row][col]);
        } else {
            break;
        }
    }

    return ansRange;
}
