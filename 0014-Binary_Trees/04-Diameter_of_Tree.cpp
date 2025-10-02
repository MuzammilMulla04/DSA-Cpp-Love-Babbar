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
    int height(struct Node* node) {
        if(node == nullptr)
            return 0;

        int h1= height(node->left);
        int h2= height(node->right);

        return max(h1, h2) + 1;
    }
public:
    int diameter(Node* root) {
        if(!root)
            return 0;
        
        int option1= diameter(root->left);
        int option2= diameter(root->right);
        int option3= height(root->left) + height(root->right) + 1;

        return max(option1, max(option2, option3));
    }
};
class SolutionOptimized {
    pair<int, int> getDiameterHeight(Node* root) {
        if(!root)
            return make_pair(0, 0);
        
        pair<int, int> left= getDiameterHeight(root->left);
        pair<int, int> right= getDiameterHeight(root->right);

        int option1= left.first;
        int option2= right.first;
        int option3= left.second + right.second + 1;

        pair<int, int> ans;
        ans.first= max(option1, max(option2, option3));
        ans.second= max(left.second, right.second) + 1;

        return ans;
    }
public:
    int diameter(Node* root) {
        if(!root)
            return 0;

        return getDiameterHeight(root).first;
    }
};
