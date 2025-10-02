#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, maxSize = 0, start = 0;
        multiset<int> window;  // Keeps track of elements in the current window

        for (int right = 0; right < n; ++right) {
            window.insert(arr[right]);

            // Maintain the condition |max - min| ≤ x
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                ++left;  // Shrink window from left
            }

            // Update longest subarray info
            if (right - left + 1 > maxSize) {
                maxSize = right - left + 1;
                start = left;
            }
        }

        return vector<int>(arr.begin() + start, arr.begin() + start + maxSize);
    }
};
