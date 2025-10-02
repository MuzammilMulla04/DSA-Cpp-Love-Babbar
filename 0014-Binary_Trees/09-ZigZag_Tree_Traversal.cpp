#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> zigZagTraversal(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;

        queue<Node*> q;
        q.push(root);

        bool leftToRight= true;
        while(!q.empty()) {
            int size= q.size();
            vector<int> result(size);

            for(int i=0; i<size; i++) {
                Node* temp= q.front();
                q.pop();

                int index= leftToRight? i: size-i-1;
                result[index]= temp->data;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);

            }
            for(auto i:result)
                ans.push_back(i);

            leftToRight= !leftToRight;
        }

        return ans;
    }
};