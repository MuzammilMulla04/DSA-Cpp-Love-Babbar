#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    unordered_set<int> s;

public:
    FindElements(TreeNode *root) {
        if (!root)
            return;
        root->val = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            s.insert(front->val);

            if (front->left) {
                front->left->val = 2 * front->val + 1;
                q.push(front->left);
            }
            if (front->right) {
                front->right->val = 2 * front->val + 2;
                q.push(front->right);
            }
        }
    }

    bool find(int target) {
        return s.count(target);
    }
};
