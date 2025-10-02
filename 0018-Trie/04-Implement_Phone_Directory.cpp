#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode() : children(26, nullptr), isTerminal(false) {}
    TrieNode(char data) : data(data), children(26, nullptr), isTerminal(false) {}
};
class Trie {
    TrieNode* root;
    void storeSuggestions(TrieNode* curr, string prefix, vector<string>& suggestions) {
        if(curr->isTerminal)
            suggestions.push_back(prefix);

        for(char ch= 'a'; ch <= 'z'; ch++) {
            TrieNode* child= curr->children[ch - 'a'];

            if(child) {
                prefix.push_back(ch);
                storeSuggestions(child, prefix, suggestions);
                prefix.pop_back();
            }
        }
    }
public:
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        if (word.empty())
            return;

        TrieNode* temp = root;
        for (char ch : word) {
            if (!temp->children[ch - 'a']) {
                temp->children[ch - 'a'] = new TrieNode(ch);
            }

            temp = temp->children[ch - 'a'];
        }

        temp->isTerminal = true;
    }
    vector<vector<string>> getSuggestions(string str) {
        vector<vector<string>> ans;
        TrieNode* temp= root;
        string prefix= "";

        for(char ch: str) {
            prefix += ch;
            TrieNode* child= temp->children[ch - 'a'];

            if(!child)
                break;

            vector<string> suggestions;
            storeSuggestions(child, prefix, suggestions);

            ans.push_back(suggestions);
            temp= child;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie t;
    for(string str: contactList)
        t.insert(str);

    vector<vector<string>> ans= t.getSuggestions(queryStr);
    return ans;
}
