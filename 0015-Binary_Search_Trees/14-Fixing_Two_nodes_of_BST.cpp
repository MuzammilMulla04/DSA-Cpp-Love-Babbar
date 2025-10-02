#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node *prev = nullptr;
    Node *first = nullptr, *middle = nullptr, *second = nullptr;

    void inorder(Node *root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev && prev->data > root->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                second = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void correctBST(Node *root) {
        inorder(root);

        if (first && second) {
            swap(first->data, second->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};
