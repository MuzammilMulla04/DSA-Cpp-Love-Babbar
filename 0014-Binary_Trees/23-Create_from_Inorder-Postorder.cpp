#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
    int findPosition(int in[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (in[i] == target) {
                in[i] = -1;
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[], int post[], int& index, int n, int inorderStart, int inorderEnd) {
        if (index < 0 || inorderStart > inorderEnd)
            return nullptr;

        int element = post[index--];
        Node* root = new Node(element);
        int position = findPosition(in, n, element);

        root->right = solve(in, post, index, n, position + 1, inorderEnd);
        root->left = solve(in, post, index, n, inorderStart, position - 1);

        return root;
    }

public:
    Node* buildTree(int in[], int post[], int n) {
        int index = n-1;
        Node* root = solve(in, post, index, n, 0, n - 1);
        return root;
    }
};
