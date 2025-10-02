#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
// Constructor
    Node(int data) {
        this->data= data;
        this->left= nullptr;
        this->right= nullptr;
    }
};
class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int target) {
        if(!root)
            return;
        if(root->data == target) {
            pre= root->left? root->left: nullptr;
            while(pre->right)
                pre= pre->right;
                
            suc= root->right? root->right: nullptr;
            while(suc->left)
                suc= suc->left;
            
            return;
        }
        
        if(root->data > target) {
            suc= root;
            findPreSuc(root->left, pre, suc, target);
        } else {
            pre= root;
            findPreSuc(root->right, pre, suc, target);
        }
    }
};