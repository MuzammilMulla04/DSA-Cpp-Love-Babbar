#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    int height(Node* root) {
        if(!root)
            return 0;
        
        int h1= height(root->left);
        int h2= height(root->right);

        return max(h1, h2) + 1;
    }
public:
    bool isBalanced(Node* root) {
        if(!root)
            return true;
        
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);

        bool difference= abs(height(root->left) - height(root->right)) <= 1;

        return (left && right && difference)? true: false;
    }
};
class SolutionOptimized {
    pair<bool, int> solve(Node* root) {
        if(!root)
            return make_pair(true, 0);
        
        pair<bool, int> left= solve(root->left);
        pair<bool, int> right= solve(root->right);

        pair<int, int> ans;
        bool difference= abs(left.second - right.second) <= 1;

        ans.first= left.first && right.first && difference;
        ans.second= max(left.second, right.second) + 1;

        return ans;
    }
public:
    bool isBalanced(Node* root) {
        if(!root)
            return true;
        
        return solve(root).first;
    }
};
