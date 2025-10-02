#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int getLength(struct Node* root) {
        if(!root)
            return 0;

        return 1 + getLength(root->left) + getLength(root->right);
    }
    bool isCBT(struct Node* root, int index, int size) {
        if(!root)
            return true;
        if(index > size)
            return false;
        
        bool leftTree= isCBT(root->left, 2*index, size);
        bool rightTree= isCBT(root->right, 2*index+1, size);
        
        return leftTree && rightTree;
    }
    bool isInOrder(struct Node* root) {
        // No Child
        if (!root->left && !root->right)
            return true;
        // Only Left Child
        if (!root->right)
            return root->data > root->left->data;

        // Both Child
        bool leftTree= isHeap(root->left);
        bool rightTree= isHeap(root->right);

        return leftTree && rightTree && (root->left->data < root->data && root->right->data < root->data);
    }
public:
    bool isHeap(struct Node *root) {
        int n= getLength(root);
        return isCBT(root, 1, n) && isInOrder(root);
    }
};
