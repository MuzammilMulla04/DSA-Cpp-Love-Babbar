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

// My Approach
 /*
pair<bool, int> checkBST(TreeNode* root) {
    if(!root)
        return {true, 0};
    if(!root->left && !root->right)
        return {true, 1};

    pair<bool, int> leftTree= checkBST(root->left);
    pair<bool, int> rightTree= checkBST(root->right);

    if(leftTree.first && rightTree.first) {
        int leftData= root->left? root->left->data: INT_MIN;
        int rightData= root->right? root->right->data: INT_MAX;

        bool isBST= leftData < root->data && root->data < rightData;

        if (isBST) {
            int size = leftTree.second + rightTree.second + 1;
            return {true, size};
        }
    }

    return {false, max(leftTree.second, rightTree.second)};
}
int largestBST(TreeNode *root) {
    pair<bool, int> currNode= checkBST(root);
    return currNode.second;
}
 */
/* Fails only this testcase:
    120 80 59 70 23 78 66 103 46 19 53 84 113 56 110 117 36 65 77 82 57 55 25 119 3 85 112 27 24 96 18 44 67 9 114 12 102 81 20 69 49 14 74 35 34 38 105 1 91 68 100 15 95 93 10 2 51 60 107 108 124 33 106 -1 47 64 123 -1 21 83 87 -1 58 88 39 37 17 72 115 -1 79 99 29 -1 32 31 116 -1 75 28 0 5 104 4 42 -1 41 11 121 -1 6 76 52 -1 13 48 94 50 98 73 43 -1 62 86 54 -1 30 40 26 -1 61 109 16 118 71 111 89 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

    Inorder of this tree:
    44 47 117 64 67 123 103 9 21 36 83 114 87 70 12 58 65 88 102 39 46 37 81 17 77 72 20 115 80 69 79 82 99 49 29 19 14 32 57 31 74 116 23 35 75 55 28
34 0 53 5 38 104 25 4 105 42 120 1 41 119 11 91 121 84 68 6 3 76 100 52 78 15 13 85 48 95 94 113 50 93 98 112 73 10 43 59 2 62 27 86 51 54 56 60 30 24 40 107 26 66 108 61 96 109 124 16 110 118 33 71 18 111 106 89
 */


// Babbar's Approach
class Info {
public:
    int minValue;
    int maxValue;
    bool isBST;
    int size;
};
Info checkBST(TreeNode* root, int& ans) {
    if(!root)
        return {INT_MAX, INT_MIN, true, 0};

    Info leftTree= checkBST(root->left, ans);
    Info rightTree= checkBST(root->right, ans);
    Info currNode;

    currNode.size = leftTree.size + rightTree.size + 1;
    currNode.minValue= min(root->data, leftTree.minValue);
    currNode.maxValue= max(root->data, rightTree.maxValue);

    if(leftTree.isBST && rightTree.isBST && (root->data > leftTree.maxValue && root->data < rightTree.minValue))
        currNode.isBST= true;
    else
        currNode.isBST= false;
    
    if(currNode.isBST)
        ans= max(ans, currNode.size);

    return currNode;
}
int largestBST(TreeNode *root) {
    int ans= 0;
    Info solve= checkBST(root, ans);
    return ans;
}