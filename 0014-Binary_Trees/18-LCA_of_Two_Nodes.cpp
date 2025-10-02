#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* lca(Node* root, int n1, int n2) {
        if(!root)
            return nullptr;
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node* leftAns= lca(root->left, n1, n2);
        Node* rightAns= lca(root->right, n1, n2);

        if(leftAns && rightAns)
            return root;
        else if(!leftAns && rightAns)
            return rightAns;
        else if(leftAns && !rightAns)
            return leftAns;
        else
            return nullptr;
    }
};