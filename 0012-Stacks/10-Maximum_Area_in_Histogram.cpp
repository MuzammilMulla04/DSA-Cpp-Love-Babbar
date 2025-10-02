#include <bits/stdc++.h>
using namespace std;

// 1. Previous/Next Smaller
class Solution {
    vector<int> previousSmallerElement(int* arr, int n) {
        vector<int> prev(n);
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            while (s.top() != -1 && curr <= arr[s.top()]) {
                s.pop();
            }

            prev[i] = s.top();
            s.push(i);
        }

        return prev;
    }
    vector<int> nextSmallerElement(int* arr, int n) {
        vector<int> next(n);
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (s.top() != -1 && curr <= arr[s.top()]) {
                s.pop();
            }

            next[i] = s.top();
            s.push(i);
        }

        return next;
    }

public:
    int largestRectangleArea(int* heights, int n) {
        vector<int> prev(n);
        vector<int> next(n);

        prev = previousSmallerElement(heights, n);
        next = nextSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }

        return area;
    }
};

// 2. Using Stack
class Solution {
public:
    int getMaxArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;  // Stack to store indices of histogram bars
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int height = arr[st.top()];  // Height of the popped bar
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;  // Width of the rectangle
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
