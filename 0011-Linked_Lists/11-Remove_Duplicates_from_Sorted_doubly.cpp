#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
//Constructor & Destructor
    Node(int data) {
        this->data= data;
        this->prev= NULL;
        this->next= NULL;
    }
    ~Node() {
        cout << this->data << " is deleted!" << endl;
        if(this->prev != NULL) {
            this->prev= NULL;
            delete prev;
        }
        if(this->next != NULL) {
            this->next= NULL;
            delete next;
        }
    }
//Craate Head & Node
    static Node* createHead() {
        return NULL;
    }
    Node* createNode() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        return new Node(data);
    }
//Insertion
    void insertAtBeg(Node*& head) {
        Node* newNode= createNode();
        if(head != NULL) {
            newNode->next= head;
            head->prev= newNode;
        }
        head= newNode;
    }
    void insertAtEnd(Node*& head) {
        Node* newNode= createNode();
        if(head == NULL) {
            head= newNode;
        } else {
            Node* temp= head;
            while(temp->next != NULL)
                temp= temp->next;
            temp->next= newNode;
            newNode->prev= temp;
        }
    }
    void insertAtPos(Node*& head) {
        int length= getLength(head);
        int pos;
        cout << "Enter Position: ";
        cin >> pos;

        if(pos <= 1) {
            insertAtBeg(head);
            return;
        } else if(pos >= length+1) {
            insertAtEnd(head);
            return;
        } else {
            Node* temp= head;
            for(int count=1; count < pos-1; count++)
                temp= temp->next;
            Node* newnNode= createNode();
            
            newnNode->next= temp->next;
            newnNode->prev= temp;
            
            temp->next->prev= newnNode;
            temp->next= newnNode;
        }
    }
//Deletion
    void deleteByPos(Node*& head) {
        int pos;
        cout << "Enter Pos: ";
        cin >> pos;

        if(pos == 1 || head == NULL) {
            head= head->next;
            delete head->prev;
            head->prev= NULL;
            return;
        }

        Node* temp= head;
        for(int count=1; count < pos; count++)
            temp= temp->next;
        
        if(temp->next == NULL) {
            temp->prev->next= NULL;
            delete temp;
        } else {
            temp->prev->next= temp->next;
            temp->next->prev= temp->prev;
            delete temp;
        }
    }
//Other Functions
    static int getLength(Node* head) {
        int count=0;
        while(head != NULL) {
            count++;
            head= head->next;
        }
        return count;
    }
    static void print(Node* head) {
        if(head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List:-" << endl;
        while(head != NULL) {
            cout << head->data << " ";
            head= head->next;
        }
        cout << endl;
    }
};

Node* uniqueSortedList(Node* head) {
    if(head == NULL)
        return head;

    for(Node* temp= head; temp != NULL && temp->next != NULL; ) {
        if(temp->data == temp->next->data) {
            Node* nodeToDelete= temp->next;
            if(temp->next->next != NULL) {
                temp->next= temp->next->next;
                temp->next->prev= temp;
            } else {
                temp->next = NULL;
            }
            delete nodeToDelete;
        } else {
            temp= temp->next;
        }
    }

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
    Node::print(head);

    head= uniqueSortedList(head);
    Node::print(head);

    cout << endl;
    return 0;
}