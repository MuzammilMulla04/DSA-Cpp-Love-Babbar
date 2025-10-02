#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
typedef struct Node Node;

class SolutionMap {
    Node* getNormalLL(Node* head) {
        Node *cloneHead = NULL;
        Node *cloneTemp = NULL;

        while (head != NULL) {
            Node *newNode = new Node(head->data);

            if (cloneHead == NULL) {
                cloneHead = newNode;
            } else {
                cloneTemp->next = newNode;
            }

            cloneTemp= newNode;
            head= head->next;
        }

        return cloneHead;
    }
    unordered_map<Node*, Node*> getMapping(Node* head, Node* cloneHead) {
        unordered_map<Node*, Node*> mapping;

        while(head != NULL) {
            mapping[head]= cloneHead;

            head= head->next;
            cloneHead= cloneHead->next;
        }

        return mapping;
    }
public:
    Node *copyList(Node *head) {
    //Get Normal LL
        Node* cloneHead= getNormalLL(head);
    //Create Mapping
        unordered_map <Node*, Node*> mapping= getMapping(head, cloneHead);
    //Connect Random Pointers
        for(Node* cloneTemp= cloneHead; head != NULL; cloneTemp= cloneTemp->next, head=head->next) {
            cloneTemp->arb= mapping.at(head->arb);
        }

        return cloneHead;
    }
};
class Solution {
    Node* getNormalLL(Node* head) {
        if(!head)
            return NULL;
        Node *cloneHead = NULL;
        Node *cloneTemp = NULL;

        while (head != NULL) {
            Node *newNode = new Node(head->data);
            newNode->next= NULL;

            if (cloneHead == NULL) {
                cloneHead = newNode;
            } else {
                cloneTemp->next = newNode;
            }

            cloneTemp= newNode;
            head= head->next;
        }

        return cloneHead;
    }
    void combineLL(Node* head, Node* cloneHead) {
        if(!head || !cloneHead)
            return;
        Node* temp= head->next;
        Node* cloneTemp= cloneHead->next;

        while(temp != NULL && cloneTemp != NULL) {
            head->next= cloneHead;
            cloneHead->next= temp;

            head= temp;
            cloneHead= cloneTemp;

            temp= temp->next;
            cloneTemp= cloneTemp->next;
        }

        head->next= cloneHead;
    }
    void connectRandomPointers(Node* head) {
        while (head != nullptr && head->next != nullptr) {
            if (head->arb != nullptr) {
                head->next->arb = head->arb->next;
            }
            head = head->next->next;
        }
    }
    void seperateLL(Node* head) {
        if(!head || !head->next) // add null check for cloneHead->next
            return;
        Node* cloneHead= head->next;

        while(head->next != NULL && cloneHead->next != NULL) {
            head->next= head->next->next;
            cloneHead->next= cloneHead->next->next;

            head= head->next;
            cloneHead= cloneHead->next;
        }

        head->next= NULL;
    }
public:
    Node *copyList(Node *head) {
        if(!head)
            return head;
        else if(head->next == NULL)
            return getNormalLL(head);
    //Get Normal LL
        Node* cloneHead= getNormalLL(head);
    //Insert clone nodes in between original nodes
        combineLL(head, cloneHead);
    //Connect Random Pointers
        connectRandomPointers(head);
    //Remove clone nodes from original list
        seperateLL(head);

        return cloneHead;
    }
};
class SolutionBabbar {
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};

int main() {
    system("cls");

    Node* node1= new Node(1);
    Node* node2= new Node(2);
    Node* node3= new Node(3);
    Node* node4= new Node(4);
    
    Node* head= node1;
    node1->next= node2;
    node2->next= node3;
    node3->next= node4;
    node4->next= nullptr;

    node1->arb= node2;
    node2->arb= node4;
    node3->arb= nullptr;
    node4->arb= nullptr;

    Solution s;
    Node* cloneHead= s.copyList(head);

    return 0;
}