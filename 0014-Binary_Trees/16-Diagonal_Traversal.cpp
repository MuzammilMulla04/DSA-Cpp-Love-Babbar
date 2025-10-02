#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void solve(Node* root, int level, map<int, vector<int>>& diagonalMap) {
    if (!root)
        return;

    diagonalMap[level].push_back(root->data);

    solve(root->left, level + 1, diagonalMap);
    solve(root->right, level, diagonalMap);
}
vector<int> diagonal(Node* root) {
    vector<int> ans;
    if (!root)
        return ans;

    map<int, vector<int>> diagonalMap;
    solve(root, 0, diagonalMap);

    for (auto map : diagonalMap) {
        for (auto data : map.second) {
            ans.push_back(data);
        }
    }

    return ans;
}


template<typename T>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};
void traverseDiagonal(TreeNode<int>* root, int level, vector<vector<int>>& ans) {
    if(!root)
        return;

    if(level == ans.size())
        ans.push_back(vector<int>());
    ans[level].push_back(root->data);
    
    traverseDiagonal(root->left, level+1, ans);
    traverseDiagonal(root->right, level, ans);
}
vector<vector<int>> diagonal(TreeNode<int>* root){
    vector<vector<int>> ans;
    traverseDiagonal(root, 0, ans);
    return ans;
}
