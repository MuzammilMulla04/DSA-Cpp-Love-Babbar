#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the current price is greater or equal
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, it means there is no greater element on the left
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());

            // Push the current index onto the stack
            st.push(i);
        }

        return span;
    }
};
