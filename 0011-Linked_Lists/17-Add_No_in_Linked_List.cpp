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
Node* getLinkedList() {
    int n;
    cout << "Enter Size of Linked List: ";
    cin >> n;
    Node* head = Node::createHead();
    while (n--)
        head->insertAtEnd(head);

    cout << endl;
    head->printLinkedList(head);
    cout << endl;

    return head;
}

Node* reverseLinkedList(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* chotaHead= reverseLinkedList(head->next);
    head->next->next= head;
    head->next= NULL;

    return chotaHead;
}
Node* addLinkedLists(Node* head1, Node* head2) {
    Node* sumHead= NULL;
    Node* temp1= head1;
    Node* temp2= head2;
    Node* sumTemp= NULL;

    int sum= 0;
    int carry= 0;

    while(temp1 != NULL || temp2 != NULL || carry != 0) {
        sum= (temp1? (temp1->data): 0) + (temp2? (temp2->data): 0) + carry;

        carry= sum/10;
        sum= sum%10;

        Node* newNode= new Node(sum);
        newNode->next= NULL;

        if(sumHead == NULL) {
            sumHead= newNode;
        } else {
            sumTemp->next= newNode;
        }

        if(temp1 != NULL)
            temp1= temp1->next;
        if(temp2 != NULL)
            temp2= temp2->next;
        sumTemp= newNode;
    }

    return sumHead;
}
Node* addTwoLists(Node* head1, Node* head2) {
//Check for leading Zeros
    while(head1->data == 0 && head1->next != NULL) {
        head1= head1->next;
    }
    while(head2->data == 0 && head2->next != NULL) {
        head2= head2->next;
    }
    
    if(head1->data == 0 && head2->data == 0) {
        return new Node(0);
    } else if(head1->data == 0) {
        return head2;
    } else if(head2->data == 0) {
        return head1;
    }
//Reverse both LL
    head1= reverseLinkedList(head1);
    head2= reverseLinkedList(head2);

    Node* sumHead= addLinkedLists(head1, head2);

    sumHead= reverseLinkedList(sumHead);
    return sumHead;
}

int main() {
    system("cls");

    Node* num1= getLinkedList();
    Node* num2= getLinkedList();

    Node* sum= addTwoLists(num1, num2);
    cout << "Sum:-" << endl;
    sum->printLinkedList(sum);

    cout << endl;
    return 0;
}