#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Approach 1
void inorder(TreeNode* root, vector<int>& arr) {
    if(!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& ans) {
    int n= arr1.size(), m= arr2.size();

    int i=0, j=0;

    while(i<n && j<m) {
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n) {
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<m) {
        ans.push_back(arr2[j]);
        j++;
    }
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2, ans;
    inorder(root1, arr1);
    inorder(root2, arr2);

    mergeTwoSortedArrays(arr1, arr2, ans);
    return ans;
}

// Approach 2
void BSTToSortedLL(TreeNode* root, TreeNode*& head) {
    if(!root)
        return;

    BSTToSortedLL(root->right, head);
    root->right= head;
    head= root;

    BSTToSortedLL(root->left, head);
    root->left= nullptr;
}
TreeNode* mergeTwoSortedLL(TreeNode* head1, TreeNode* head2) {
    if(!head1)
        return head2;
    if(!head2)
        return head1;

    TreeNode* head= new TreeNode(-1);

    TreeNode* temp= head;
    while(head1 && head2) {
        if(head1->data < head2->data) {
            temp->right= head1;
            temp= head1;
            head1= head->right;
        } else {
            temp->right= head2;
            temp= head2;
            head2= head2->right;
        }
    }

    if(head1) {
        temp->right= head1;
        temp= head1;
    }
    if(head2) {
        temp->right= head2;
        temp= head2;
    }
    
    return head->right;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    TreeNode* temp= nullptr;
    BSTToSortedLL(root1, temp);
    root1= temp;
    temp= nullptr;
    BSTToSortedLL(root2, temp);
    root2= temp;

    TreeNode* root= mergeTwoSortedLL(root1, root2);
    vector<int> ans;

    while(root) {
        ans.push_back(root->data);
        root= root->right;
    }

    return ans;
}

// If asked to create BST using mergedLL
int length(TreeNode* head) {
    int count= 0;
    while(head) {
        count++;
        head= head->right;
    }
    return count;
}
TreeNode* LLtoBST(TreeNode* head, int n) {
    if(n <= 0 || !head)
        return nullptr;

    TreeNode* leftTree= LLtoBST(head, n/2);

    TreeNode* root= head;
    root->left= leftTree;

    head= head->right;

    TreeNode* rightTree= LLtoBST(head, n/2 - 1);
    root->right= rightTree;

    return root;
}
