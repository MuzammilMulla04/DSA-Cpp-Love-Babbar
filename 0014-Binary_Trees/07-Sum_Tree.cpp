#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
    pair<bool, int> solve(Node* root) {
        if(!root)
            return make_pair(true, 0);
        
        if(!root->left && !root->right)
            return make_pair(true, root->data);
        
        pair<bool, int> left= solve(root->left);
        pair<bool, int> right= solve(root->right);
        int sum= left.second + right.second;

        pair<bool, int> ans;
        ans.first= left.first && right.first && (sum == root->data);
        ans.second= 2*sum;
        
        return ans;
    }
public:
    bool isSumTree(Node* root) {
        return solve(root).first;
    }
};
