#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    // Constructor & Destructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~Node() {
        cout << this->data << " is deleted!" << endl;
        if (this->next != nullptr) {
            this->next = nullptr;
            delete this->next;
        }
    }
    // Create Nodew
    Node* createNode() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        Node* newNode = new Node(data);
        return newNode;
    }
    // Create Linked List(head & tail)
    static Node* createHead() {
        return nullptr;
    }
    // Traversal
    void print(Node* head) {
        if (head == nullptr) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    // Insertion
    void insertAtBeg(Node*& head) {
        Node* newNode = createNode();
        if (head != nullptr) {
            newNode->next = head;
        }
        head = newNode;
    }
    void insertAtEnd(Node*& head) {
        Node* newNode = createNode();
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void insertAtPos(Node*& head) {
        int pos;
        cout << "Enter Position: ";
        cin >> pos;
        // Inserting At Head
        if (pos == 1) {
            insertAtBeg(head);
            return;
        }
        Node* temp = head;
        for (int count = 1; count < pos - 1; temp = temp->next)
            count++;
        // Inserting At Tail
        if (temp->next == nullptr) {
            insertAtEnd(head);
            return;
        }
        // Inserting at any other Position
        Node* newNode = createNode();
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Deletion
    void deleteByPos(Node*& head) {
        if (head == nullptr) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        int pos;
        cout << "Enter Position: ";
        cin >> pos;
        // Delete at Beg
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Delete at any other Position
        Node* temp = head;
        Node* prev = nullptr;
        for (int count = 1; count < pos; count++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    void deleteByValue(Node*& head) {
        int value;
        cout << "Enter Value: ";
        cin >> value;

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->data != value && temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        // If temp at Head
        if (temp == head) {
            head = head->next;
            delete temp;
            return;
        }
        // If not Found!
        if (temp == nullptr) {
            cout << value << " is not present!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
};

Node* kReverse(Node* head, int k) {
    // Base Case
    if (head == nullptr)
        return head;

    // Solve 1 Case
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    // If group is possible?
    int count = 0;
    for (Node* temp = curr; temp != nullptr; temp = temp->next) {
        count++;
    }
    if (count < k) {
        return head;
    } else {
        for (count = 0; curr != nullptr && count < k; count++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Recursion will solve other cases
        if (next != nullptr)
            head->next = kReverse(next, k);

        // Return head of Reversed LL
        return prev;
    }
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    Node* head = Node::createHead();
    while (n--)
        head->insertAtEnd(head);

    head->print(head);

    int k;
    cout << "Enter K: ";
    cin >> k;

    head = kReverse(head, k);

    head->print(head);

    cout << endl;
    return 0;
}