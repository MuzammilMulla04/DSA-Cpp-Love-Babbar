#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode* findPredecessor(TreeNode* root, int target) {
    if(!root)
        return nullptr;
    
    if(root->data >= target) {
        return findPredecessor(root->left, target);
    }

    TreeNode* pre= findPredecessor(root->right, target);
    return pre? pre: root;
}
TreeNode* findSuccessor(TreeNode* root, int target) {
    if(!root)
        return nullptr;
    
    if(root->data <= target) {
        return findSuccessor(root->right, target);
    }

    TreeNode* suc= findSuccessor(root->left, target);
    return suc? suc: root;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    TreeNode* pre= findPredecessor(root, key);
    TreeNode* suc= findSuccessor(root, key);

    pair<int, int> ans;
    ans.first= pre? pre->data: -1;
    ans.second= suc? suc->data: -1;
    
    return ans;
}