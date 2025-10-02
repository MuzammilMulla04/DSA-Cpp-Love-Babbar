#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
public:
    vector<int> verticalOrder(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;

        map<int, map<int, vector<int>>> mapping;
        queue<pair<Node*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()) {
            pair<Node*, pair<int, int>> temp= q.front();
            q.pop();

            Node* frontNode= temp.first;
            int distance= temp.second.first;
            int level= temp.second.second;

            mapping[distance][level].push_back(frontNode->data);

            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(distance-1, level+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(distance+1, level+1)));
        }

        for(auto element: mapping) {            // For each mapping,
            for(auto pair: element.second) {    // In each pair of level & vector
                for(auto data: pair.second) {   // For each element of vector
                    ans.push_back(data);        // Store it
                }
            }
        }

        return ans;
    }
};
