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

int main() {
    system("cls");

    Node* head= Node::createHead();
    int option=0;

    do {
        system("cls");
        option= menu(option);

        switch(option) {
            case 1: {
                head->insertAtBeg(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 2: {
                head->insertAtEnd(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
            case 3: {
                head->insertAtPos(head);
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
                head->deleteByPos(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
/*            case 6: {
                head->deleteByValue(head);
                cout << endl << "Press any Key to Continue!" << endl;
                system("pause>0");
                break;
            }
 */            case 0: {
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
