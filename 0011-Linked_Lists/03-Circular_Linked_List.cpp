#include <iostream>
using namespace std;

int menu(int option) {
    cout << "\t\tMENU" << endl;
    cout << "\t1. Insert after Value" << endl;
    cout << "\t2. Print" << endl;
    cout << "\t3. Delete after Value" << endl;
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
//Create Linked List(head)
    static Node* createHead() {
        return NULL;
    }
//Traversal
    void print(Node* head) {
        if(head  == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        Node* temp= head;
        do {
            cout << temp->data << " ";
            temp= temp->next;
        } while(temp != head);
        cout << endl;
    }
//Insertion
    void insertAfterValue(Node*& head) {
        int value;
        cout << "Enter Value: ";
        cin >> value;

        Node* newNode= createNode();
        if(head == NULL) {
            head=newNode;
            newNode->next= head;
        }

        Node* temp= head;
        while(temp->data != value && temp->next != head)
            temp= temp->next;
        newNode->next= temp->next;
        temp->next= newNode;
    }
//Deletion
    void deleteByValue(Node*& head) {
// Empty List
        if(head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }
        int value;
        cout << "Enter Value: ";
        cin >> value;
//Only 1 Node & found
        if(head->next == head && head->data == value) {
            delete head;
            head= NULL;
            return;
        }
//More than 1 Node       
        Node* prev= head;
        Node* temp= prev->next;
        while(temp->data != value && temp->next != head->next) {
            prev= temp;
            temp= temp->next;
        }
    //If not Found!        
        if(temp->data != value) {
            cout << value << " not Found!" << endl;
            return;
        }        
    //If Found
        if(temp == head)
            head= head->next;
        prev->next= temp->next;
        delete temp;
    }
};

int main() {
    system("cls");

    Node* head= Node::createHead();
    int option=0;

    do {
        system("cls");
        option= menu(option);

        switch(option) {
            case 1: {
                head->insertAfterValue(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 2: {
                head->print(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 3: {
                head->deleteByValue(head);
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