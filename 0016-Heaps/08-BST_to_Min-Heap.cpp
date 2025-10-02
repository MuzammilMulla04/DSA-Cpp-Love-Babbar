#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

class Solution {
    void getMinHeap(BinaryTreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (!root)
            return;

        getMinHeap(root->left, minHeap);
        minHeap.push(root->data);
        getMinHeap(root->right, minHeap);
    }
    void setMinHeap(BinaryTreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (!root)
            return;

        root->data = minHeap.top();
        minHeap.pop();
        setMinHeap(root->left, minHeap);
        setMinHeap(root->right, minHeap);
    }
public:
    BinaryTreeNode* convertBST(BinaryTreeNode* root) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        getMinHeap(root, minHeap);
        setMinHeap(root, minHeap);
        return root;
    }
};
class SolutionOptimized {
    void getMinHeap(BinaryTreeNode* root, vector<int>& arr) {
        if (!root)
            return;

        getMinHeap(root->left, arr);
        arr.push_back(root->data);
        getMinHeap(root->right, arr);
    }
    void setMinHeap(BinaryTreeNode* root, vector<int>& arr, int& index) {
        if (!root)
            return;

        root->data= arr[index++];
        
        setMinHeap(root->left, arr, index);
        setMinHeap(root->right, arr, index);
    }
public:
    BinaryTreeNode* convertBST(BinaryTreeNode* root) {
        vector<int> arr;
        getMinHeap(root, arr);
        int i=0;
        setMinHeap(root, arr, i);
        return root;
    }
};
