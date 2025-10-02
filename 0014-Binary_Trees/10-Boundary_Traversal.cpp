#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
    void printLeftBoundary(Node* root, vector<int>& ans) {
        if(!root)
            return;
        if(!root->left && !root->right)
            return;

        ans.push_back(root->data);

        if(root->left)
            printLeftBoundary(root->left, ans);
        else if(root->right)
            printLeftBoundary(root->right, ans);
    }
    void printLeafNodes(Node* root, vector<int>& ans) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }

        printLeafNodes(root->left, ans);
        printLeafNodes(root->right, ans);
    }
    void printRightBoundary(Node* root, vector<int>& ans) {
        if(!root)
            return;
        if(!root->left && !root->right)
            return;
        
        if(root->right)
            printRightBoundary(root->right, ans);
        else if(root->left)
            printRightBoundary(root->left, ans);

        ans.push_back(root->data);
    }
public:
    vector<int> boundary(Node* root) {
        vector<int> ans;
        if(!root)
            return ans;

        // Print Root
        ans.push_back(root->data);
        // Print Left-Boundary
        if(root->left)
            printLeftBoundary(root->left, ans);

        // Print Leaf-Nodes
        if(root->left || root->right)
            printLeafNodes(root, ans);

        // Print Right-Boundary
        if(root->right)
            printRightBoundary(root->right, ans);
        
        return ans;
    }
};
