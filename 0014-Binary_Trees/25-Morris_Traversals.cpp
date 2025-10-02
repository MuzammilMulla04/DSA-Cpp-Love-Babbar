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
class binaryTree {
    Node* root;
public:
    binaryTree() {
        root= nullptr;
        // root= createBinaryTreeInorder();
        root= createBinaryTreeLevelorder();
    }
    Node* createBinaryTreeLevelorder() {
        int data;
        cout << "Enter data for Root: ";
        cin >> data;

        root= new Node(data);

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* temp= q.front();
            q.pop();

            cout << "Enter data for Left of Node " << temp->data << ": ";
            cin >> data;

            if(data != -1) {
                temp->left= new Node(data);
                q.push(temp->left);
            }

            cout << "Enter data for Right of Node " << temp->data << ": ";
            cin >> data;

            if(data != -1) {
                temp->right= new Node(data);
                q.push(temp->right);
            }
        }

        return root;
    }
    void preorderTraversalIterative() {
        if(!root)
            return;
        
        stack<Node*> s;
        s.push(root);

        cout << endl << "Preorder Iterative Traversal: ";
        while(!s.empty()) {
            Node* temp= s.top();
            s.pop();

            if(temp) {
                cout << temp->data << " ";
            }

            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        cout << endl;
    }
    void inorderTraversalIterative() {
        if(!root)
            return;
        
        stack<Node*> s;
        Node* curr= root;

        cout << endl << "Inorder Iterative traversal: ";
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr= curr->left;
            }

            curr= s.top();
            s.pop();

            cout << curr->data << " ";
            curr= curr->right;
        }
        cout << endl;
    }
    void postorderTraversalIterative() {
        if(!root)
            return;
        
        stack<Node*> s;
        vector<int> revAns;
        s.push(root);

        cout << endl << "Postorder Iterative traversal: ";
        while(!s.empty()) {
            Node* temp= s.top();
            s.pop();

            revAns.push_back(temp->data);

            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }

        for(int i=0, j=revAns.size()-1; i<j; i++, j--)
            swap(revAns[i], revAns[j]);

        for(auto i: revAns)
            cout << i << " ";

        cout << endl;
    }
// Morris Traversals
    void morrisPreorder() {
        Node* curr= root;

        cout << endl << "Morris Preorder Traversal: ";
        while(curr) {
            if(!curr->left) {
                cout << curr->data << " ";
                curr= curr->right;
            } else {
                Node* predecessor= curr->left;

                while(predecessor->right && predecessor->right != curr) {
                    predecessor= predecessor->right;
                }

                if(!predecessor->right) {           // Create temp link
                    predecessor->right= curr;
                    cout << curr->data << " ";
                    curr= curr->left;
                } else {                            // Delete temp link
                    predecessor->right= nullptr;
                    curr= curr->right;
                }
            }
        }
        cout << endl;
    }
    void morrisInorder() {
        Node* curr= root;

        cout << endl << "Morris Inorder Traversal: ";
        while(curr) {
            if(!curr->left) {
                cout << curr->data << " ";
                curr= curr->right;
            } else {
                Node* predecessor= curr->left;

                while(predecessor->right && predecessor->right != curr) {
                    predecessor= predecessor->right;
                }

                if(!predecessor->right) {           // Create temp link
                    predecessor->right= curr;
                    curr= curr->left;
                } else {                            // Delete temp link
                    predecessor->right= nullptr;
                    cout << curr->data << " ";
                    curr= curr->right;
                }
            }
        }
        cout << endl;
    }
    void morrisPostorder() {
        Node* curr= root;

        cout << endl << "Morris Postorder Traversal: ";
        while(curr) {
            if(!curr->left) {
                curr= curr->right;
            } else {
                Node* predecessor= curr->left;

                while(predecessor->right && predecessor->right != curr) {
                    predecessor= predecessor->right;
                }

                if(!predecessor->right) {           // Create temp link
                    predecessor->right= curr;
                    cout << curr->data << " ";
                    curr= curr->left;
                } else {                            // Delete temp link
                    predecessor->right= nullptr;
                    cout << curr->data << " ";
                    curr= curr->right;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    system("cls");

    binaryTree bt;
    // For Level Order Creation: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    bt.postorderTraversalIterative();
    bt.morrisPostorder();

    return 0;
}