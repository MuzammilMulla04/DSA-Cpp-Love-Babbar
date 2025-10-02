#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node {
public:
    char data;
    vector<Node*> children;
    bool isTerminal;

    Node(): children(26, nullptr), isTerminal(false) {}
    Node(char ch): data(ch), children(26, nullptr), isTerminal(false) {}
};
class Trie {
    Node* root;
    void insertHelper(Node* root, string word) {
        if(word.length() == 0) {
            root->isTerminal= true;
            return;
        }

        int index= word[0] - 'a';
        if(!root->children[index]) {
            root->children[index]= new Node(word[0]);
        }

        insertHelper(root->children[index], word.substr(1));
    }
    bool searchHelper(Node* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index= word[0] - 'a';
        if(!root->children[index]) {
            return false;
        }

        return searchHelper(root->children[index], word.substr(1));
    }
    bool startsWithHelper(Node* root, string prefix) {
        if(prefix.length() == 0)
            return true;
        
        int index= prefix[0] - 'a';
        if(!root->children[index])
            return false;
        
        return startsWithHelper(root->children[index], prefix.substr(1));
    }
public:
    Trie() {
        root= new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertHelper(root, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchHelper(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithHelper(root, prefix);
    }
};