#include <iostream>
#include <stack>
#include <string>
using namespace std;

void solve(stack<int>& s, int bottom) {
    if(s.empty()) {
        s.push(bottom);
        return;
    }

    int temp= s.top();
    s.pop();
    solve(s, bottom);
    s.push(temp);
}
stack<int> pushAtBottom(stack<int>& myStack, int x)  {
    solve(myStack, x);
    return myStack;
}
