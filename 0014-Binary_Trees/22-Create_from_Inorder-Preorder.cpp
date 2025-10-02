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
    Node* solve(int in[], int pre[], int& index, int n, int inorderStart, int inorderEnd) {
        if (index >= n || inorderStart > inorderEnd)
            return nullptr;

        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, n, element);

        root->left = solve(in, pre, index, n, inorderStart, position - 1);
        root->right = solve(in, pre, index, n, position + 1, inorderEnd);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int index = 0;
        Node* root = solve(in, pre, index, n, 0, n - 1);
        return root;
    }
};
class SolutionOptimized {
    map<int*, int> createMap(int in[], int n) {
        map<int*, int> nodeToIndex;
        for (int i = 0; i < n; i++)
            nodeToIndex[in + i] = i;
        return nodeToIndex;
    }

    Node* solve(int in[], int pre[], map<int*, int>& nodeToIndex, int& index, int n, int inorderStart, int inorderEnd) {
        if (index >= n || inorderStart > inorderEnd)
            return nullptr;

        int position = nodeToIndex[pre + index];
        int element = pre[index++];
        Node* root = new Node(element);

        root->left = solve(in, pre, nodeToIndex, index, n, inorderStart, position - 1);
        root->right = solve(in, pre, nodeToIndex, index, n, position + 1, inorderEnd);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int index = 0;
        map<int*, int> nodeToIndex = createMap(in, n);
        return solve(in, pre, nodeToIndex, index, n, 0, n - 1);
    }
};