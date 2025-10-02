#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void makelist(TreeNode<int>* root, TreeNode<int>*& head) {
    if (!root)
        return;

    makelist(root->right, head);

    root->right = head;
    head = root;

    makelist(root->left, head);
    root->left = NULL;

    return;
}
TreeNode<int>* flatten(TreeNode<int>* root) {
    TreeNode<int>* head = NULL;
    makelist(root, head);
    return head;
}