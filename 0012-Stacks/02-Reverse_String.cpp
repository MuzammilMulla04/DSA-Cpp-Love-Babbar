#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseString(const string& str) {
    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        s.push(str[i]);
    }
    string ans= "";
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    cin >> str;

    string rev= reverseString(str);

    cout << "Reverse of String: " << rev << endl;

    return 0;
}