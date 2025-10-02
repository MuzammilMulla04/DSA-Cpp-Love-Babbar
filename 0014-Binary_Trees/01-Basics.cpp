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
// Constructor Functions
    Node* createBinaryTreeInorder() {
        int data;
        // cout << "Enter Data: ";
        cin >> data;

        if(data == -1) {
            return nullptr;
        }
        Node* temp= new Node(data);
        if(root == nullptr)
            root= temp;

        // cout << "For Left-Child of Node " << temp->data << endl;
        temp->left= createBinaryTreeInorder();

        // cout << "For Right-Child of Node " << temp->data << endl;
        temp->right= createBinaryTreeInorder();

        return temp;
    }
//Traversal Recursive Functions
    void inorderRecursion(const Node* temp) const {
        if(!temp)
            return;

        inorderRecursion(temp->left);
        cout << temp->data << " ";
        inorderRecursion(temp->right);
    }
    void preorderRecursion(const Node* temp) const {
        if(!temp)
            return;

        cout << temp->data << " ";
        preorderRecursion(temp->left);
        preorderRecursion(temp->right);
    }
    void postorderRecursion(const Node* temp) const {
        if(!temp)
            return;

        postorderRecursion(temp->left);
        postorderRecursion(temp->right);
        cout << temp->data << " ";
    }

public:
// Constructor
    binaryTree() {
        root= nullptr;
        // root= createBinaryTreeInorder();
        root= createBinaryTreeLevelorder();
    }
// Getter
    Node* getRoot() {
        return root;
    }
//Traversals 
    // (Iterative)
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
    // (Recursive)
    void inorderTraversalRecursive() const {
        cout << endl << "Inorder Recursive Traversal: ";
        inorderRecursion(root);
        cout << endl;
    }
    void preorderTraversalRecursive() const {
        cout << endl << "Preorder Recursive Traversal: ";
        preorderRecursion(root);
        cout << endl;
    }
    void postorderTraversalRecursive() const {
        cout << endl << "Postorder Recursive Traversal: ";
        postorderRecursion(root);
        cout << endl;
    }
// Functions
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
};

int main() {
    system("cls");

    binaryTree bt;
    // For Inorder Creation: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // For Level Order Creation: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    bt.levelOrderTraversal();

    // bt.postorderTraversalRecursive();
    // bt.postorderTraversalIterative();

    return 0;
}