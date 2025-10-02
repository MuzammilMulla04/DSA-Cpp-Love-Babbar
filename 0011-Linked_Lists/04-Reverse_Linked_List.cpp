#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
   public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};
void printLinkedList(LinkedListNode<int>* head) {
    do {
        cout << head->data << " ";
        head= head->next;
    } while(head != NULL);
    cout << endl;
}

LinkedListNode<int> *reverseLinkedListIterative(LinkedListNode<int> *head) {
// Iterative
    if (head == NULL || head->next == NULL)
        return head;
    LinkedListNode<int> *prev = NULL, *current = head, *forward = NULL;
    while (current != NULL) {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

void reverse(LinkedListNode<int> **head, LinkedListNode<int> *prev, LinkedListNode<int> *curr) {
    if (curr == NULL) {
        *head = prev;
        return;
    }
    reverse(head, curr, curr->next);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedListRecursive(LinkedListNode<int> *head) {
    // Recursive
    LinkedListNode<int> *prev = NULL, *curr = head;
    reverse(&head, prev, curr);
    return head;
}

LinkedListNode<int> *reverseLinkedListRecursive1(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int>* smallerHead= reverseLinkedListRecursive1(head->next);

    head->next->next= head;
    head->next= NULL;

    return smallerHead;
}

int main() {
    system("cls");

    LinkedListNode<int> *head = NULL;
    LinkedListNode<int> node1(1);
    LinkedListNode<int> node2(2);
    LinkedListNode<int> node3(3);
    LinkedListNode<int> node4(4);
    LinkedListNode<int> node5(5);

    head= &node1;
    node1.next= &node2;
    node2.next= &node3;
    node3.next= &node4;
    node4.next= &node5;

    printLinkedList(head);
    head= reverseLinkedListIterative(head);
    printLinkedList(head);

    cout << endl;

    printLinkedList(head);
    head= reverseLinkedListRecursive(head);
    printLinkedList(head);

    cout << endl;

    printLinkedList(head);
    head= reverseLinkedListRecursive1(head);
    printLinkedList(head);

    cout << endl;
    return 0;
}