#include <bits/stdc++.h>
using namespace std;
void print(char currentChar, int roundBracketASCII, int squareBracketASCII, int curlyBracketASCII) {
    cout << currentChar << ": " << roundBracketASCII << " " << squareBracketASCII << " " << curlyBracketASCII;
    cout << endl;
}
bool isValidASCII(string str) {
    int asciiExp = 0;

    for(int currentChar: str) {
        switch (currentChar) {
            case '(': 
            case '[': 
            case '{': {
                asciiExp += currentChar;
                break;
            }
            case ')': {
                //A condition
                    asciiExp -= '(';
                break;
            }
            case ']': {
                //A condition
                    asciiExp -= '[';
                break;
            }
            case '}': {
                //A condition
                    asciiExp -= '{';
                break;
            }
        }
    }

    return asciiExp == 0;
}
bool isValidGPT(string str) {
    int roundBracketASCII= 0;
    int squareBracketASCII= 0;
    int curlyBracketASCII= 0;

    print(0, roundBracketASCII, squareBracketASCII, curlyBracketASCII);
    for(int currentChar: str) {
        switch (currentChar) {
            case '(':  {
                roundBracketASCII += currentChar;
                break;
            }
            case '[':  {
                squareBracketASCII += currentChar;
                break;
            }
            case '{': {
                curlyBracketASCII += currentChar;
                break;
            }
            case ')': {
                roundBracketASCII -= '(';
                break;
            }
            case ']': {
                squareBracketASCII -= '[';
                break;
            }
            case '}': {
                curlyBracketASCII -= '{';
                break;
            }
        }
    print(currentChar, roundBracketASCII, squareBracketASCII, curlyBracketASCII);
    }

    return roundBracketASCII + squareBracketASCII + curlyBracketASCII == 0;
}

int main() {
    system("cls");

    string s;
    cout << "Enter String: ";
    getline(cin, s);

    cout << endl;
    if(isValidGPT(s))
        cout << endl << "Valid!" << endl;
    else
        cout << endl << "Invalid!" << endl;

    cout << endl;
    return 0;
}