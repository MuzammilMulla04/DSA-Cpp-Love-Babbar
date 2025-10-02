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

void createInorder(TreeNode<int>* root, vector<TreeNode<int>*>& in) {
    if(!root)
        return;

    createInorder(root->left, in);
    in.push_back(root);
    createInorder(root->right, in);
}
TreeNode<int>* convertToBalancedBST(vector<TreeNode<int>*>& in, int start, int end) {
    if(start > end)
        return nullptr;
    
    int mid= start+ (end-start)/2;
    TreeNode<int>* root= in[mid];

    root->left= convertToBalancedBST(in, start, mid-1);
    root->right= convertToBalancedBST(in, mid+1, end);

    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<TreeNode<int>*> in;
    createInorder(root, in);

    return convertToBalancedBST(in, 0, in.size()-1);
}
