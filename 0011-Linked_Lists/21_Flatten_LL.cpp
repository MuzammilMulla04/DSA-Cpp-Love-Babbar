#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* mergeChildLists(Node* first, Node* second) {
    Node* dummy= new Node(-1);
    Node* temp= dummy;

    while(first && second) {
        if(first->data <= second->data) {
            temp->child= first;
            temp= first;
            first= first->child;
        } else {
            temp->child= second;
            temp= second;
            second= second->child;
        }
        temp->next= nullptr;
    }
    temp->child= first? first: second;
    if(dummy->child) {
        dummy->child->next= nullptr;
    }
    temp->child->next= nullptr;
    return dummy->child;
}
Node *flattenLinkedList(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* nextList= flattenLinkedList(head->next);
    Node* ans= mergeChildLists(head, nextList);
    return ans;
}
