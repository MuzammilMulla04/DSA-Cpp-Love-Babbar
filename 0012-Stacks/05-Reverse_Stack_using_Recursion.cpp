#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int bottom) {
    if(s.empty()) {
        s.push(bottom);
        return;
    }

    int temp= s.top();
    s.pop();
    insertAtBottom(s, bottom);
    s.push(temp);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return;

    int temp= stack.top();
    stack.pop();
    reverseStack(stack);

    insertAtBottom(stack, temp);
}