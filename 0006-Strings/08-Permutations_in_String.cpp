#include<iostream>
#include<string>
using namespace std;

bool checkCountEqual(int arr1[], int arr2[]) {
    for(int i=0; i<26; i++) {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}
bool checkInclusion(string part, string str) {
    int countOfPart[26]= {0};
    for(int i=0; i<part.length(); i++)
        countOfPart[part[i]-'a']++;

    int i=0, windowSize= part.length();
    int countOfStr[26]= {0};

    while(i<windowSize && i<str.length())
        countOfStr[str[i++]-'a']++;

    if(checkCountEqual(countOfStr, countOfPart))
        return true;

    while(i<str.length()) {
        int newCharIndex = str[i]-'a';
        int oldCharIndex = str[i-windowSize]-'a';
        countOfStr[newCharIndex]++;
        countOfStr[oldCharIndex]--;
        if(checkCountEqual(countOfPart, countOfStr)) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    system("cls");

    string part, str;
    cout << "Enter substring: ";
    cin >> part;
    cout << "Enter string: ";
    cin >> str;

    if(checkInclusion(part, str)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    cout << endl;
    return 0;
}