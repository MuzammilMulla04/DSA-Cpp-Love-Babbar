#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> st, minStack;

public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);

        if (minStack.empty() || minStack.top() > x)
            minStack.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if (st.empty())
            return;

        if (minStack.top() == st.top())
            minStack.pop();
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        return st.empty() ? -1 : st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};
