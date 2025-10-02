#include <iostream>
#include <map>
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
bool detectloop(Node* head) {
    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    for(Node* temp= head; temp != NULL; temp=temp->next) {
        if(visited[temp] == true)
            return true;
        
        visited[temp]= true;
    }
    
    return false;
}

bool floydDetectLoop(Node* head, Node*& slow, Node*& fast) {
    if(head == NULL)
        return false;
    do {
        slow= slow->next;
        if(slow == NULL)
            return false;
        fast= fast->next->next;

        if(fast == slow)
            return true;
    } while(fast != NULL);
    
    return false;
}
Node* giveStartOfLoop(Node* head) {
    Node* slow= head;
    Node* fast= head;

    if(floydDetectLoop(head, slow, fast)) {
        slow= head;

        while(slow != fast) {
            slow= slow->next;
            fast= fast->next;
        }
     
        return slow;
    }

    return NULL;
}
void removeLoop(Node* head) {
    Node* loopStart= giveStartOfLoop(head);
    Node* temp= loopStart;

    while(temp->next != loopStart) {
        temp= temp->next;
    }

    temp->next= NULL;
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
    
    removeLoop(head);
    head->printLinkedList(head);

    cout << endl;
    return 0;
}