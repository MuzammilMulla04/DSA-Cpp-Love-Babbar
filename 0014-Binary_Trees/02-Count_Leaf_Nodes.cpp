#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, int& count) {
    if(root == nullptr) {
        count++;
        return;
    }
    
    solve(root->left, count);
    solve(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root) {
    int count= 0;
    solve(root, count);
    return count;
}
