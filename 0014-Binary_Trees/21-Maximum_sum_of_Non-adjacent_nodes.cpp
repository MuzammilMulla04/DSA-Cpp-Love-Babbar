#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

class Solution {
    pair<int, int> solve(Node* root) {
        if(!root)
            return make_pair(0, 0);
        
        pair<int, int> leftAns= solve(root->left);
        pair<int, int> rightAns= solve(root->right);

        pair<int, int> result;
        result.first= leftAns.second + rightAns.second + root->data;
        result.second= max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return result;
    }
public:
    int getMaxSum(Node *root) {
        pair<int, int> sums= solve(root);
        return max(sums.first, sums.second);
    }
};
