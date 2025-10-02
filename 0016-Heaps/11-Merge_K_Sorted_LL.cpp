#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

//Approach1
Node* mergeKLists(vector<Node*>& listArray) {
    int n= listArray.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++) {
        Node* temp= listArray[i];

        while(temp) {
            minHeap.push(temp->data);
            temp= temp->next;
        }
    }

    Node* head= new Node(-1);
    Node* temp= head;
    while(!minHeap.empty()) {
        int data= minHeap.top();
        minHeap.pop();

        Node* newNode= new Node(data);
        temp->next= newNode;
        temp= newNode;
    }

    return head;
}

// Approach2
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*>& listArray) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(auto temp: listArray) {
        minHeap.push(temp);
    }

    Node* head= new Node(-1);
    Node* temp= head;
    while(!minHeap.empty()) {
        Node* topNode= minHeap.top();
        minHeap.pop();

        temp->next= topNode;
        temp= topNode;

        if(topNode->next)
            minHeap.push(topNode->next);
    }

    return head->next;
}
