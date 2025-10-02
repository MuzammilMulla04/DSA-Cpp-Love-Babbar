#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
    void solve(Node* root, int level, vector<int>& ans) {
        if(!root)
            return;
        
        if(level == ans.size())
            ans.push_back(root->data);

        solve(root->right, level+1, ans);
        solve(root->left, level+1, ans);
    }
public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};
