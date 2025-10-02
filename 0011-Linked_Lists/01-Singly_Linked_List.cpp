#include <iostream>
using namespace std;

int menu(int option) {
    cout << "\t\tMENU" << endl;
    cout << "\t1. Insert at Beg" << endl;
    cout << "\t2. Insert at End" << endl;
    cout << "\t3. Insert at Pos" << endl;
    cout << "\t4. Print" << endl;
    cout << "\t5. Delete by Pos" << endl;
    cout << "\t6. Delete by Value" << endl;
    cout << "\t0. Exit" << endl;

    cout << endl << "Enter Option: ";
    cin >> option;

    return option;
}
class Node {
public:
    int data;
    Node* next;
//Constructor & Destructor
    Node(int data) {
        this->data= data;
        this->next= NULL;
    }
    ~Node() {
        cout << this->data << " is deleted!" << endl;
        if(this->next != NULL) {
            this->next= NULL;
            delete this->next;
        }
    }
//Create Node
    Node* createNode() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        Node* newNode= new Node(data);
        return newNode;
    }
//Create Linked List(head & tail)
    static Node* createHead() {
        return NULL;
    }
    static Node* createTail() {
        return NULL;
    }
//Traversal
    void print(Node* head) {
        if(head  == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        while(head != NULL) {
            cout << head->data << " ";
            head= head->next;
        }
        cout << endl;
    }
//Insertion
    void insertAtBeg(Node*& head, Node*& tail) {
        Node* newNode= createNode();
        if(head == NULL) {
            head= newNode;
            tail= head;
        } else {
            newNode->next= head;
            head= newNode;
        }
    }
    void insertAtPos(Node*& head, Node*& tail) {
        int pos;
        cout << "Enter Position: ";
        cin >> pos;
// Inserting At Head
        if(pos == 1) {
            insertAtBeg(head, tail);
            return;
        }
        Node* temp= head;
        for(int count=1; count < pos-1; temp= temp->next)
            count++;
//Inserting At Tail
        if(temp->next == NULL) {
            insertAtEnd(head, tail);
            return;
        }
//Inserting at any other Position
        Node* newNode= createNode();
        newNode->next= temp->next;
        temp->next= newNode;
    }
    void insertAtEnd(Node*& head, Node*& tail) {
        Node* newNode= createNode();
        if(tail == NULL) {
            head= newNode;
            tail= head;
        } else {
            tail->next= newNode;
            tail= tail->next;
        }
    }
//Deletion
    void deleteByPos(Node*& head, Node*& tail) {
        if(head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        int pos;
        cout << "Enter Position: ";
        cin >> pos;
//Delete at Beg
        if(pos == 1) {
            Node* temp= head;
            head= head->next;
            delete temp;
            return;
        }
        
//Delete at any other Position
        Node* temp= head;
        Node* prev= NULL;
        for(int count=1; count < pos; count++) {
            prev= temp;
            temp= temp->next;
        }
        if(temp == NULL)
            tail= prev;
        prev->next= temp->next;
        delete temp;
    }
    void deleteByValue(Node*& head, Node*& tail) {
        int value;
        cout << "Enter Value: ";
        cin >> value;

        Node* temp= head;
        Node* prev= NULL;
        while(temp->data != value && temp != NULL) {
            prev= temp;
            temp= temp->next;
        }
//If temp at Head
        if(temp == head) {
            head= head->next;
            delete temp;
            return;
        }
//If not Found!        
        if(temp == NULL) {
            cout << value << " is not present!" << endl;
            tail= prev;
            return;
        }

        prev->next= temp->next;
        delete temp;
    }
};

int main() {
    system("cls");

    Node* head= Node::createHead();
    Node* tail= Node::createTail();
    int option=0;

    do {
        system("cls");
        option= menu(option);

        switch(option) {
            case 1: {
                head->insertAtBeg(head, tail);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 2: {
                head->insertAtEnd(head, tail);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 3: {
                head->insertAtPos(head, tail);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 4: {
                head->print(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 5: {
                head->deleteByPos(head, tail);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 6: {
                head->deleteByValue(head, tail);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 0: {
                cout << "Bye!" << endl;
                break;
            }
            default: {
                cout << "Invalid Option!" << endl;
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
            }
        }
    } while(option != 0);

    cout << endl;
    return 0;
}