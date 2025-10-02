#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string& str) {
        int n = str.size();
        if (n <= 1) return str;  // If the string has 0 or 1 character, it's already a palindrome.

        int start = 0, maxLen = 1;

        // Function to expand around a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && str[left] == str[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    start = left;
                    maxLen = currLen;
                }
                left--;
                right++;
            }
        };

        // Iterate over each character as a potential palindrome center
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);      // Check for odd-length palindromes
            expandAroundCenter(i, i + 1);  // Check for even-length palindromes
        }

        return str.substr(start, maxLen);  // Extract and return the longest palindrome substring
    }
};
