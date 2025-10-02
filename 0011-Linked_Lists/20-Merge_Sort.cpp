#include <bits/stdc++.h>
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
        // cout << "Enter data: ";
        cin >> data;

        Node* newNode = new Node(data);
        return newNode;
    }
    // Create Linked List(head & tail)
    static Node* createHead() {
        return NULL;
    }
    // Traversal
    void printLinkedList(Node* head) {
        if (head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    // Insertion
    void insertAtBeg(Node*& head) {
        Node* newNode = createNode();
        if (head != NULL) {
            newNode->next = head;
        }
        head = newNode;
    }
    void insertAtEnd(Node*& head) {
        Node* newNode = createNode();
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
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
        if (temp->next == NULL) {
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
        if (head == NULL) {
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
        Node* prev = NULL;
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
        Node* prev = NULL;
        while (temp->data != value && temp != NULL) {
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
        if (temp == NULL) {
            cout << value << " is not present!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
};

Node* findMiddle(Node* head) {
    Node* temp = head->next;
    while (temp != NULL && temp->next != NULL) {
        head = head->next;
        temp = temp->next->next;
    }
    return head;
}

void solve(Node* head1, Node* head2) {
    if (head1->next == NULL) {
        head1->next = head2;
        return;
    }
    Node* temp1 = head1->next;
    Node* temp2 = head2->next;

    while (temp1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data && head2->data <= temp1->data) {
            head1->next = head2;
            head2->next = temp1;

            head1 = head2;
            head2 = temp2;

            if (temp2 != NULL)
                temp2 = temp2->next;
        } else {
            head1 = temp1;
            temp1 = temp1->next;

            if (temp1 == NULL) {
                head1->next = head2;
                return;
            }
        }
    }
}
Node* merge(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node* head = NULL;
    if (head1->data <= head2->data) {
        head = head1;
        solve(head1, head2);
    } else {
        head = head2;
        solve(head2, head1);
    }

    return head;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    // Divide
    Node* mid = findMiddle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    cout << endl;
    left->printLinkedList(left);
    right->printLinkedList(right);
    system("pause>0");

    // Sort
    left = mergeSort(left);
    right = mergeSort(right);

    cout << endl;
    left->printLinkedList(left);
    right->printLinkedList(right);
    system("pause>0");
    // Merge
    head = merge(left, right);

    cout << endl;
    head->printLinkedList(head);
    system("pause>0");

    return head;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    Node* head = Node::createHead();
    while (n--)
        head->insertAtEnd(head);
    head->printLinkedList(head);

    head = mergeSort(head);
    head->printLinkedList(head);

    return 0;
}