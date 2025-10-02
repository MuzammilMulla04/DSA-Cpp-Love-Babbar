#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;

        map<int, int> mapping;
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair<Node*, int> temp= q.front();
            q.pop();

            Node* frontNode= temp.first;
            int distance= temp.second;

            int distance= temp.second;

            if(!mapping[distance])
                mapping[distance]= (frontNode->data);

            if(frontNode->left)
                q.push(make_pair(frontNode->left, distance-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, distance+1));
        }

        for(auto map: mapping) {
            ans.push_back(map.second);
        }

        return ans;
    }
};
