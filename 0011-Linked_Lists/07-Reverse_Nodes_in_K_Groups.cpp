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

Node* getListAfterReverseOperation(Node* head, int sizeOfArray, int arr[]) {
	head->printLinkedList(head);
//Base Case
	if(head == NULL)
		return head;
//Solve 1 Case
	if(arr[0] == 0) {
		arr++;
		sizeOfArray--;
	}

	Node *prev= NULL, *curr= head, *forward= head->next;
	if(arr[0] == 1)
		head->next= getListAfterReverseOperation(forward, sizeOfArray-1, arr+1);

	for(int count=0; curr != NULL && count < arr[0]; count++) {
		curr->next= prev;
		prev= curr;
		curr= forward;
		forward= forward->next;	
	}

//Recursion solves other cases
	if(forward != NULL && sizeOfArray != 1)
		head->next= getListAfterReverseOperation(forward, sizeOfArray-1, arr+1);
	else
		head->next= forward;

	return prev;
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
    
	int m;
    cout << "Enter Size for Array: ";
    cin >> n;
    int *arr= new int[m];
    cout << "Enter Elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    head= getListAfterReverseOperation(head, n, arr);
	cout << "OUTSIDE!" << endl;
    head->printLinkedList(head);

    cout << endl;
    return 0;
}