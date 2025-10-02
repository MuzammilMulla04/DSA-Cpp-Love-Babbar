#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val = 0) {
        this -> val = val;
    }
    ListNode(int val, ListNode* next) {
        this -> val = val;
        this -> next = next;
    }
};

ListNode* reverseLL(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* newHead= reverseLL(head->next);
    head->next->next= head;
    head->next= NULL;

    return newHead;
}
void add1inLL(ListNode* head) {
    if(head == NULL)
        return;

    int sum=0, carry=1;
    while(head->next != NULL) {
        sum= head->val + carry;
        carry= sum/10;
        sum %= 10;

        head->val= sum;
        if(!carry)
            return;
        head= head->next;
    }

    if(head->next == NULL) {
        sum= head->val + carry;
        carry= sum/10;
        sum %= 10;

        head->val= sum;
        if(carry) {
            ListNode* newNode= new ListNode(1, NULL);
            head->next= newNode;
        }
    }

    return;
}
ListNode* addOneToLinkedList(ListNode* head) {
    head= reverseLL(head);
    add1inLL(head);
    head= reverseLL(head);
    return head;
}
void printLL(ListNode* head) {
    cout << endl << "Linked List: ";
    while(head != NULL) {
        cout << head->val << " ";
        head= head->next;
    }
    cout << endl;
}

int main() {
    system("cls");

    ListNode* node1= new ListNode(9, NULL);
    ListNode* node2= new ListNode(9, NULL);
    ListNode* node3= new ListNode(9, NULL);
    ListNode* node4= new ListNode(9, NULL);
    ListNode* node5= new ListNode(9, NULL);

    ListNode* head= node1;
    node1->next= node2;
    node2->next= node3;
    node3->next= node4;
    node4->next= node5;

    printLL(head);
    head= addOneToLinkedList(head);
    printLL(head);

    return 0;
}