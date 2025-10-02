#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    // Constructor
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    void flatten(Node* root) {
        Node* curr= root;

        while(curr) {
            if(curr->left) {
                Node* pred= curr->left;
                while(pred->right)
                    pred= pred->right;
                
                pred->right= curr->right;
                curr->right= curr->left;
                curr->left= nullptr;
            }
            curr= curr->right;
        }
    }
};
