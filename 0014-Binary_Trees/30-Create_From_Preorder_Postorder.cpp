#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int& preIndex, int postStart, int postEnd) {
        if (preIndex >= preorder.size() || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (postStart == postEnd)
            return root;

        int partition = postStart;
        while (partition < postEnd && preorder[preIndex] != postorder[partition]) {
            ++partition;
        }

        root->left = solve(preorder, postorder, preIndex, postStart, partition);
        root->right = solve(preorder, postorder, preIndex, partition + 1, postEnd - 1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        return solve(preorder, postorder, preIndex, 0, postorder.size() - 1);
    }
};