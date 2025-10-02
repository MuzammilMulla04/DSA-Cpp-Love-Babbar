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

void inorder(BinaryTreeNode<int> *root, vector<int>& arr) {
    if(!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
bool twoSumInBST(BinaryTreeNode<int> *root, int target) {
    vector<int> arr;
    inorder(root, arr);

    for(int i=0, j=arr.size()-1; i<j;) {
        if(arr[i] + arr[j] == target)
            return true;

        if(arr[i] + arr[j] > target)
            j--;
        else
            i++;
    }

    return false;
}