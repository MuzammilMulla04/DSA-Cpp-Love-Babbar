#include<bits/stdc++.h>
using namespace std;

// Babbar
/*
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
    void insert(Node* root, string word) {
        if(word.length() == 0) {
            root->isTerminal= true;
            return;
        }

        int index= word[0]- 'a';
        if(!root->children[index]) {
            root->children[index]= new Node(word[0]);
        }

        insert(root->children[index], word.substr(1));
    }
    bool search(Node* root, string word) {
        if(word.length() == 0)
            return root->isTerminal;

        int index= word[0]- 'a';
        if(!root->children[index])
            return false;

        return search(root->children[index], word.substr(1));
    }
    void remove(Node* root, string word) {
        if(word.length() == 0) {
            root->isTerminal= false;
            return;
        }

        int index= word[0]- 'a';
        if(!root->children[index]) {
            return;
        }

        remove(root->children[index], word.substr(1));
    }
public:
    Trie() {
        root= new Node();
    }
    void insertWord(string word) {
        insert(root, word);
    }
    bool searchWord(string word) {
        return search(root, word);
    }
    void removeWord(string word) {
        return remove(root, word);
    }
};

void TrieBabbar() {
    Trie t;
    t.insertWord("Muza");

    if(t.searchWord("Muza"))
        cout << "Present!" << endl;
    else
        cout << "Not Present!" << endl;

    t.removeWord("Muza");

    if(t.searchWord("Muza"))
        cout << "Present!" << endl;
    else
        cout << "Not Present!" << endl;
}
 */
// Yui
template <typename T>
class TrieNode {
public:
    T data;
    unordered_map<T, TrieNode*> children;
    bool isTerminal;

    TrieNode(): isTerminal(false) {}
    TrieNode(T data): data(data), isTerminal(false) {}
};
class Trie {
    TrieNode<char>* root;
    void deleteWord(TrieNode<char>* root, string word, int index) {
        if(index >= word.size()) {
            delete root;
            return;
        }

        deleteWord(root->children[word[index]], word, index+1);

        if(!root->isTerminal && root->children.empty()) {
            delete root;
        }
    }
public:
// Constructor
    Trie() {
        root= new TrieNode<char>();
    }
// Functions
    void insert(string word) {
        if(word.empty())
            return;

        TrieNode<char>* temp= root;
        for(char letter: word) {
            if(!temp->children.count(letter))
                temp->children[letter]= new TrieNode<char>(letter);

            temp= temp->children[letter];
        }
        temp->isTerminal= true;
    }
    bool search(string word) {
        if(word.empty())
            return true;

        TrieNode<char>* temp= root;
        for(char letter: word) {
            if(!temp->children.count(letter))
                return false;

            temp= temp->children[letter];
        }
        return temp->isTerminal;
    }
    void remove(string word) {
        if(word.empty())
            return;

        TrieNode<char>* temp= root;
        for(char letter: word) {
            if(!temp->children.count(letter))
                return;

            temp= temp->children[letter];
        }

        if(temp->isTerminal) {
            temp->isTerminal= false;

            if(temp->children.empty())
                deleteWord(root, word, 0);
        }
    }
};

int main() {
    system("cls");

    // TrieBabbar();

    cout << "All Clear!" << endl;
    return 0;
}