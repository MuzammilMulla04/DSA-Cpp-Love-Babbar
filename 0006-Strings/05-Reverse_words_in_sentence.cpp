#include<bits/stdc++.h>
using namespace std;

string trim(const string& str) {
    cout << str.size() << endl;
// Starting Spaces
    int startPos= 0;
    while(str[startPos] == ' ')
        startPos++;
// Trailing Spaces
    int endPos= str.size() - 1;
    while(str[endPos] == ' ')
        endPos--;
// New Length
    int newLength= endPos - startPos + 1;

    return str.substr(startPos, newLength);
}

string reverseString(string str) {
    string trimmedStr= trim(str);
    
    vector<string> words;
    for(int i=0; i<trimmedStr.size(); ) {
        string word= trimmedStr.substr(i, trimmedStr.find_first_of(' ', i));

        i +=  word.size();

        words.push_back(word);
    }

    for(string& word: words) {
        cout << word << "-";
    }


    return trimmedStr;
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    getline(cin, str);

    string ans= reverseString(str);
    // cout << endl << "-" << ans << "-" << endl;

    return 0;
}