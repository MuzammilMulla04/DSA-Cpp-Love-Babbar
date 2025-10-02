#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* findPartition(Node* head, int pivot) {
    if (!head)
        return nullptr;  // Edge case: empty list
    
    Node* lessHead = nullptr;    // New head for nodes < pivot
    Node* lessTail = nullptr;    // Tail for nodes < pivot
    Node* greaterHead = nullptr; // New head for nodes >= pivot
    Node* greaterTail = nullptr; // Tail for nodes >= pivot
    
    Node* current = head;
    while (current) {
        Node* next = current->next; // Save next node
        current->next = nullptr;    // Detach current node
        
        if (current->data < pivot) {
            // Insert into less list
            if (!lessHead) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            // Insert into greater or equal list
            if (!greaterHead) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        
        current = next;
    }
    
    if (lessTail) {
        // Link the two lists
        lessTail->next = greaterHead;
        return lessHead;
    }
    
    return greaterHead;
}
