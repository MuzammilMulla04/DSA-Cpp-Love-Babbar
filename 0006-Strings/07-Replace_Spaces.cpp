#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string str){ //Space complexity: O(n)
    string temp;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' ')
            temp += "@40";
        else
            temp += str[i];
    }
    return temp;
}
string replaceSpacesInPlace(string str) {   //Only possible if assumed that given string has sufficient extra space
    int n=str.length(), spaceCount=0;
    for(int i=0; i<n; i++) {
        if(str[i] == ' ')
            spaceCount++;
    }
    for(int i=0; str[i] == ' '; i++)
        spaceCount--;       //Spaces before String
    for(int i=n-1; str[i] == ' '; i--)
        spaceCount--;       //Trailing Spaces after String

    int newLength= n + spaceCount;
    for(int i=newLength, j=n; j>=0; ) {
        if(str[j] == ' ') {
            str[i--]= '0';
            str[i--]= '4';
            str[i--]= '@';
            j--;

        } else {
            str[i--]= str[j--];
        }
    }
    return str;    
}

int main() {
    system("cls");

    string sentence;
    cout << "Enter String: ";
    getline(cin, sentence, '\n');

    cout << "String after replacing spaces is :-" << endl << replaceSpaces(sentence) << endl;
    cout << "String after replacing spaces in-place is :-" << endl << replaceSpacesInPlace(sentence) << endl;

    cout << endl;
    return 0;
}