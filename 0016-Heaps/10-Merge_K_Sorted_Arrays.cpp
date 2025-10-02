#include <bits/stdc++.h>
using namespace std;

// Approach1
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    int n= kArrays.size();
    int m= kArrays[0].size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            minHeap.push(kArrays[i][j]);
        }
    }

    while(!minHeap.empty()) {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}

// Approach2
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
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    vector<int> ans;

    for(int i=0; i<k; i++) {
        Node* newNode= new Node(kArrays[i][0], i, 0);
        minHeap.push(newNode);
    }

    while(!minHeap.empty()) {
        Node* topNode= minHeap.top();
        minHeap.pop();

        ans.push_back(topNode->data);

        int row= topNode->row;
        int col= topNode->col + 1;
        if(col < kArrays[row].size()) {
            Node* newNode= new Node(kArrays[row][col], row, col);
            minHeap.push(newNode);
        }
    }

    return ans;
}
