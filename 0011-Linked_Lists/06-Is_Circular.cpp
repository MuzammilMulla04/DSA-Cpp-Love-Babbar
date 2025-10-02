#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    // Constructor & Destructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << this->data << " is deleted!" << endl;
        if (this->next != NULL) {
            this->next = NULL;
            delete this->next;
        }
    }
    // Create Node
    Node* createNode() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        Node* newNode = new Node(data);
        return newNode;
    }
    // Create Linked List(head)
    static Node* createHead() {
        return NULL;
    }
    // Traversal
    void print(Node* head) {
        if (head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    // Insertion
    void insertAfterValue(Node*& head, int value = -1) {
        Node* newNode = createNode();
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }

        Node* temp = head;
        while (temp->data != value && temp->next != head)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Deletion
    void deleteByValue(Node*& head) {
        // Empty List
        if (head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        int value;
        cout << "Enter Value: ";
        cin >> value;
        // Only 1 Node & found
        if (head->next == head && head->data == value) {
            delete head;
            head = NULL;
            return;
        }
        // More than 1 Node
        Node* prev = head;
        Node* temp = prev->next;
        while (temp->data != value && temp->next != head->next) {
            prev = temp;
            temp = temp->next;
        }
        // If not Found!
        if (temp->data != value) {
            cout << value << " not Found!" << endl;
            return;
        }
        // If Found
        if (temp == head)
            head = head->next;
        prev->next = temp->next;
        delete temp;
    }
};
bool isCircular(Node* head) {
    if (head == NULL || head->next == head)
        return true;

    Node* temp = head->next;
    while (temp != head && temp != NULL)
        temp = temp->next;

    if (temp == head)
        return true;
    else
        return false;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    Node* head = Node::createHead();
    while (n--)
        head->insertAfterValue(head);

    head->print(head);

    if(isCircular(head))
        cout << "It is a Circular Linked List!" << endl;  
    else
        cout << "It is not a Circular Linked List!" << endl;

    cout << endl;
    return 0;
}