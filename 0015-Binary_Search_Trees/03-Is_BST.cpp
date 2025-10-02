#include <bits/stdc++.h>
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

bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if(!root)
        return true;

    if(min <= root->data && root->data <= max) {
        bool left= isBST(root->left, min, root->data);
        bool right= isBST(root->right, root->data, max);

        return left && right;
    }

    return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}