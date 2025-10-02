#include <bits/stdc++.h>
using namespace std;

// Approach 1
class Element {
public:
    char ch;
    int data;

    Element(char ch, int data): ch(ch), data(data) {}
};
class Compare {
public:
    bool operator()(Element a, Element b) {
        return a.data < b.data;
    }
};
string reArrangeString1(string &str) {
    unordered_map<char, int> count;

    for(char ch: str) {
        count[ch]++;
    }

    priority_queue<Element, vector<Element>, Compare> maxHeap;
    for(auto row: count) {
        maxHeap.push(Element(row.first, row.second));
    }

    string ans= "";
    char prevTop= '\0';
    while(!maxHeap.empty()) {
        Element top= maxHeap.top();
        maxHeap.pop();

        if(top.ch == prevTop && !maxHeap.empty()) {
            Element top2= maxHeap.top();
            maxHeap.pop();
            maxHeap.push(top);
            top= top2;
        }

        ans += top.ch;
        top.data--;
        prevTop= top.ch;

        if(top.data > 0) {
            maxHeap.push(top);
        }
    }

/*     int n= ans.size();
    for(int i=1; i<n-1; i++) {
        if(ans[i-1] == ans[i] || ans[i] == ans[i+1])
            return "not possible";
    }
 */
    return ans;
}

// Approach 2
string reArrangeString(string &str) {
    vector<int> freq(26, 0);
    for(char ch: str) {
        freq[ch - 'a']++;
    }

    vector<pair<char, int>> charCount;
    for(int i=0; i<freq.size(); i++) {
        charCount.push_back(make_pair('a' + i, freq[i]));
    }

    sort(charCount.begin(), charCount.end(), [](auto a, auto b) {
        return a.second > b.second;
    });

    int n= str.length();
    vector<pair<char, int>> :: iterator it= charCount.begin();
    for(int i=0; i<n; i+=2) {
        if(it->second <= 0) {
            it++;
        }
        
        str[i]= it->first;
        it->second--;
    }
    for(int i=1; i<n; i+=2) {
        if(it->second <= 0) {
            it++;
        }

        str[i]= it->first;
        it->second--;
    }

    for(int i=1; i<n; i++) {
        if(str[i-1] == str[i])
            return "not possible";
    }

    return str;
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    cin >> str;

    string ans= reArrangeString(str);

    cout << "Answer: " << ans << endl;

    return 0;
}