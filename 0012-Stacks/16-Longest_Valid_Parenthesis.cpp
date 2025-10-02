#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        int left = 0, right = 0, maxSize = 0;

        // Left to Right Scan
        for (char ch : str) {
            if (ch == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxSize = max(maxSize, 2 * right);
            } else if (right > left) {
                left = right = 0;  // Reset if more `)`
            }
        }

        // Right to Left Scan (handles extra `(` cases)
        left = right = 0;
        for (int i = str.size() - 1; i >= 0; --i) {
            if (str[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxSize = max(maxSize, 2 * left);
            } else if (left > right) {
                left = right = 0;  // Reset if more `(`
            }
        }

        return maxSize;
    }
};
