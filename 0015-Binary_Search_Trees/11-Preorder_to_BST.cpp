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

    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

// Approach-1
BinaryTreeNode<int>* solve(vector<int> &arr, int start, int end) {
    if(start > end)
        return nullptr;
    
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[start]);
    int count= 0;
    for(int i=start+1; i<=end; i++) {
        if(arr[start] > arr[i])
            count++;
    }
    int pos= start+count;

    root->left= solve(arr, start+1, pos);
    root->right= solve(arr, pos+1, end);

    return root;
}
BinaryTreeNode<int> *preorderToBST(vector<int> &preorder) {
    return solve(preorder, 0 , preorder.size()-1);
 }

// Approach-2
BinaryTreeNode<int>* solveOptimized(vector<int> &preorder, int& index, int min= INT_MIN, int max= INT_MAX) {
    if(index>=preorder.size())
        return nullptr;
    if(preorder[index] < min || preorder[index] > max)
        return nullptr;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(preorder[index]);
    index++;

    root->left= solveOptimized(preorder, index, min, root->data);
    root->right= solveOptimized(preorder, index, root->data, max);

    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int index= 0;
    return solveOptimized(preorder, index);
}


