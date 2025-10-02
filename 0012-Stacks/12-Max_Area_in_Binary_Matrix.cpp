const int MAX = 4;
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> previousSmallerElement(int* arr, int n) {
        vector<int> prev(n);
        stack<int> s;
        s.push(-1);

        for(int i=0; i<n; i++) {
            int curr= arr[i];

            while(s.top() != -1 && curr <= arr[s.top()]) {
                s.pop();
            }

            prev[i]= s.top();
            s.push(i);
        }

        return prev;
    }
    vector<int> nextSmallerElement(int* arr, int n) {
        vector<int> next(n);
        stack<int> s;
        s.push(-1);

        for(int i=n-1; i>=0; i--) {
            int curr= arr[i];

            while(s.top() != -1 && curr <= arr[s.top()]) {
                s.pop();
            }

            next[i]= s.top();
            s.push(i);
        }

        return next;
    }
    int largestRectangleArea(int* heights, int n) {
        vector<int> prev(n);
        vector<int> next(n);

        prev= previousSmallerElement(heights, n);
        next= nextSmallerElement(heights, n);

        int area= INT_MIN;
        for(int i=0; i<n; i++) {
            int l= heights[i];

            if(next[i] == -1) {
                next[i]= n;
            }

            int b= next[i] - prev[i] - 1;

            int newArea= l * b;
            area= max(area, newArea);
        }

        return area;
    }
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area= largestRectangleArea(M[0], m);

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                M[i][j]= (M[i][j] == 0)? 0: M[i][j] + M[i-1][j];
            }

            area= max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};
