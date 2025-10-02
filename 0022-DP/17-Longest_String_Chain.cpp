#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStringChain(vector<string> &words) {
        // Sort words by length (ascending)
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string &word : words) {
            dp[word] = 1;  // Every word starts as a chain of length 1

            // Try removing each character to find predecessors
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);

                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }

            maxLength = max(maxLength, dp[word]);  // Update global max
        }

        return maxLength;
    }
};
