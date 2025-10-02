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
    void solve(Node* root, int& count, int k, vector<int> path) {
        if(!root)
            return;
        
        path.push_back(root->data);

        solve(root->left, count, k, path);
        solve(root->right, count, k, path);

        for(int i= path.size()-1, sum= 0; i>=0; i--) {
            sum += path[i];
            if(sum == k)
                count++;
        }

        path.pop_back();
    }
public:
    int sumK(Node* root, int k) {
        vector<int> path;
        int count= 0;

        solve(root, count, k, path);
        return count;
    }
};
