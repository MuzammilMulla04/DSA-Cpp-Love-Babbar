#include<bits/stdc++.h>
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
    Node* mapParent_and_findTarget(Node* root, int target, map<Node*, Node*>& parent) {
        if(!root)
            return nullptr;
        
        Node* targetNode= nullptr;
        queue<Node*> q;
        q.push(root);
        parent[root]= nullptr;

        while(!q.empty()) {
            Node* frontNode= q.front();
            q.pop();

            if(frontNode->data == target)
                targetNode= frontNode;
            
            if(frontNode->left) {
                parent[frontNode->left]= frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                parent[frontNode->right]= frontNode;
                q.push(frontNode->right);
            }
        }

        return targetNode;
    }
    int burnTree(Node* targetNode, map<Node*, Node*>& parent) {
        if(!targetNode)
            return 0;
        
        int time= 0;
        map<Node*, bool> isBurned;
        queue<Node*> q;
        q.push(targetNode);
        isBurned[targetNode]= true;

        while(!q.empty()) {
            bool isBurning= false;
            int size= q.size();

            for(int i=0; i<size; i++) {
                Node* frontNode= q.front();
                q.pop();

                if(frontNode->left && !isBurned[frontNode->left]) {
                    isBurning= true;
                    isBurned[frontNode->left]= true;
                    q.push(frontNode->left);
                }
                if(frontNode->right && !isBurned[frontNode->right]) {
                    isBurning= true;
                    isBurned[frontNode->right]= true;
                    q.push(frontNode->right);
                }
                if(parent[frontNode] && !isBurned[parent[frontNode]]) {
                    isBurning= true;
                    isBurned[parent[frontNode]]= true;
                    q.push(parent[frontNode]);
                }
            }

            if(isBurning)
                time++;
        }

        return time;
    }
public:
    int minTime(Node *root, int target) {
    // Create Child-Parent Mapping & Find Target Node
        map<Node*, Node*> parent;
        Node* targetNode= mapParent_and_findTarget(root, target, parent);
    // Burn the Tree!
        int time= burnTree(targetNode, parent);
        return time;
    }
};