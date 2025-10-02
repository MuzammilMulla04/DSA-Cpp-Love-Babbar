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
class BST {
    Node* root;
// Helpers
    Node* insertHelper(Node* temp, int data) {
        if(!temp)
            return new Node(data);

        if(temp->data > data) {
            temp->left= insertHelper(temp->left, data);
        } else {
            temp->right= insertHelper(temp->right, data);
        }

    }
    Node* deleteHelper(Node* root, int target) {
        if(!root)
            return root;
        if(root->data == target) {
            if(!root->left && !root->right) {   //0 child
                delete root;
                return nullptr;
            } else if(!root->left || !root->right) {   //1 child
                Node* temp= root->left? root->left: root->right;
                delete root;
                return temp;
            } else {  //2 child
                Node* suc= inorderSuccessor(root, target);
                root->data= suc->data;
                root= deleteHelper(root, suc->data);
                return root;
            }
        }

        if(root->data > target) {
            root->left= deleteHelper(root->left, target);
        } else {
            root->right= deleteHelper(root->right, target);
        }

        return root;
    }
public:
// Constructor
    BST() {
        root= nullptr;
        create();
    }
// Insertion
    void insertBST(int data) {
        root= insertHelper(root, data);
    }
// Traversals
    void levelOrderTraversal() const {
        if(!root) {
            cout << "Tree is Empty!" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        cout << endl << "Level-Order Traversal:-" << endl;
        while(!q.empty()) {
            Node* temp= q.front();
            q.pop();

            if(temp) {
                cout << temp->data << " ";

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            } else {
                cout << endl;
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        cout << endl;
    }
    void inorder() {
        if(!root)
            return;

        stack<Node*> s;
        Node* curr= root;

        cout << endl << "Inorder traversal: ";
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
// Deletion
    void deleteBST() {
        int target;
        cout << "Enter Node to delete: ";
        cin >> target;

        root= deleteHelper(root, target);
    }
// Functions
    Node* getRoot() {
        return root;
    }
    void create() {
        int data;

        cout << "Enter data (STOP: -1): ";
        cin >> data;

        while(data != -1) {
            insertBST(data);
            // cout << "Enter data (STOP: -1): ";
            cin >> data;
        }
    }
    bool search(int target) {
        Node* temp= root;

        while(temp) {
            if(temp->data == target)
                return true;
            else if(temp->data > target)
                temp= temp->left;
            else
                temp= temp->right;
        }

        return false;
    }
    int min() {
        Node* temp= root;
        while(temp->left)
            temp= temp->left;

        return temp->data;
    }
    int max() {
        Node* temp= root;
        while(temp->right)
            temp= temp->right;

        return temp->data;
    }
    Node* inorderPredeccessor(Node* root, int target) {
        if (!root)
            return NULL;
        
        if (root->data >= target)
            return inorderPredeccessor(root->left, target);
        
        Node* pre = inorderPredeccessor(root->right, target);
        return (pre ? pre : root);
    }
    Node* inorderSuccessor(Node* root, int target) {
        if (!root)
            return NULL;
        
        if (root->data <= target)
            return inorderSuccessor(root->right, target);
        
        Node* suc = inorderSuccessor(root->left, target);
        return (suc ? suc : root);
    }
};

int main() {
    system("cls");

    BST b;
    b.levelOrderTraversal();
/* 
    int target;
    cout << "Enter Node: ";
    cin >> target;

    Node* pre= b.inorderPredeccessor(b.getRoot(), target);
    Node* suc= b.inorderSuccessor(b.getRoot(), target);

    cout << "Pre: " << pre->data << endl;
    cout << "Suc: " << suc->data << endl;
 */
    return 0;
}