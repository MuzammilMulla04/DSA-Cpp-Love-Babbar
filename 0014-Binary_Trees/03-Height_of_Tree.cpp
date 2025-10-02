#include<bits/stdc++.h>
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
public:
    int height(struct Node* node) {
        if(node == nullptr)
            return 0;

        int h1= height(node->left);
        int h2= height(node->right);

        return max(h1, h2) + 1;
    }
};