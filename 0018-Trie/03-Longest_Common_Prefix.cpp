#include <bits/stdc++.h>
using namespace std;

// Approach 1 [SC: O(1)]
string longestCommonPrefix(vector<string>& arr, int n) {
    string ans = "";
    int index = 0;
    bool isCommon = true;

    while (isCommon) {
        char ch = index < arr[0].size() ? arr[0][index] : '\0';
        for (string str : arr) {
            if (index < str.size() && ch != str[index]) {
                isCommon = false;
                break;
            }
        }

        if (isCommon) {
            ans += ch;
            index++;
        }
    }

    return ans;
}
// Yui
string longestCommonPrefix(vector<string>& arr, int n) {
    string ans = "";
    if (n == 0) return ans;

    for (int i = 0; i < arr[0].size(); ++i) {
        char ch = arr[0][i];

        for (int j = 1; j < n; ++j) {
            if (i >= arr[j].size() || arr[j][i] != ch) {
                return ans;
            }
        }

        ans += ch;
    }

    return ans;
}

// Approach 3 [SC: O(m*n)]
class TrieNode {
public:
    char data;
    vector<TrieNode*> children;
    int childrenCount;
    bool isTerminal;

    TrieNode() : children(26, nullptr), childrenCount(0), isTerminal(false) {}
    TrieNode(char data) : data(data), children(26, nullptr), childrenCount(0), isTerminal(false) {}
};
class Trie {
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        if (word.empty())
            return;

        TrieNode* temp = root;
        for (char ch : word) {
            if (!temp->children[ch - 'a']) {
                temp->children[ch - 'a'] = new TrieNode(ch);
                temp->childrenCount++;
            }

            temp = temp->children[ch - 'a'];
        }

        temp->isTerminal = true;
    }
    string getLongestCommonPrefix(string str) {
        string ans = "";

        TrieNode* temp = root;
        for (char ch : str) {
            if (temp->childrenCount != 1)
                break;

            ans += ch;
            temp = temp->children[ch - 'a'];
        }

        return ans;
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie t;
    for (string str : arr) {
        t.insert(str);
    }

    string ans = t.getLongestCommonPrefix(arr[0]);
    return ans;
}
