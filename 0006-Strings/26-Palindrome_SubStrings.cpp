#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPS(string& str) {
        int n = str.size();
        int count = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && str[left] == str[right]) {
                if (right - left + 1 >= 2)  // Min Length 2
                    ++count;

                ++right;
                --left;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);      // Odd Palindrome
            expand(i, i + 1);  // Even Palindrome
        }

        return count;
    }
};
