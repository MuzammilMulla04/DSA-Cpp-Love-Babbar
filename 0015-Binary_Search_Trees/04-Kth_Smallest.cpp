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

int kthSmallest(BinaryTreeNode<int>* root, int& k) {
    if (!root)
        return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    k--;
    if (k == 0)
        return root->data;

    return kthSmallest(root->right, k);
}
int kthSmallestMorris(BinaryTreeNode<int>* root, int& k) {
    if (!root)
        return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    k--;
    if (k == 0)
        return root->data;

    return kthSmallest(root->right, k);
}
