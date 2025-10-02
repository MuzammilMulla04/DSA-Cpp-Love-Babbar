#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node* solve(Node* root, int& k, int node) {
    if(!root)
        return nullptr;
    if(root->data == node)
        return root;
    
    Node* leftAns= solve(root->left, k, node);
    Node* rightAns= solve(root->right, k, node);

    if(leftAns || rightAns) {
        k--;
        if(k == 0)
            return root;
        return leftAns? leftAns: rightAns;
    }
    return nullptr;
}
int kthAncestor(Node *root, int k, int node) {
    Node* ansNode= solve(root, k, node);
    return ansNode && ansNode->data != node? ansNode->data: -1;
}
