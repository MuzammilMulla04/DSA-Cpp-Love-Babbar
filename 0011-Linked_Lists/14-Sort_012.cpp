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

Node* sort012Approach1(Node* head) {    //Data Replacement allowed!

    if(head == NULL || head->next == NULL)
        return head;

    int freq[3]= {0};
    for(Node* temp= head; temp != NULL; temp= temp->next)
        freq[temp->data]++;

    for(Node* temp= head; temp != NULL; temp= temp->next) {
        if(freq[0] != 0) {
            temp->data= 0;
            freq[0]--;
        } else if(freq[1] != 0) {
            temp->data= 1;
            freq[1]--;
        } else {
            temp->data= 2;
            freq[2]--;
        }
    }

    return head;
}

void insertAtTail(Node*& tailPointer, Node* curr) {
    tailPointer->next= curr;
    tailPointer= curr;
}
Node* sort012Approach2(Node* head) {    //Data Replacement not allowed!
    if(head == NULL || head->next ==  NULL)
        return head;

// Create 3 dummy LL
    Node* zeroHead= new Node(-1), *zeroTail= zeroHead;
    Node* oneHead= new Node(-1), *oneTail= oneHead;
    Node* twoHead= new Node(-1), *twoTail= twoHead;

// Insert 0s, 1s, and 2s in Dummy LL
    for(Node* temp= head; temp != NULL; temp= temp->next) {
        switch(temp->data) {
            case 0:
                insertAtTail(zeroTail, temp);
            break;
            case 1:
                insertAtTail(oneTail, temp);
            break;
            case 2:
                insertAtTail(twoTail, temp);
            break;
        }
    }

// Merge 3 Dummy Lists
    head= zeroHead->next;
    if(oneHead->next != NULL) {
        zeroTail->next= oneHead->next;
    } else {
        zeroTail->next= twoHead->next;
    }
    oneTail->next= twoHead->next;
    twoTail->next= NULL;

// Delete Dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size for Linked List: ";
    cin >> n;

    Node* head = Node::createHead();
    while (n--)
        head->insertAtEnd(head);
    head->printLinkedList(head);

    // head= sort012Approach1(head);
    head= sort012Approach2(head);
    head->printLinkedList(head);

    cout << endl;
    return 0;
}