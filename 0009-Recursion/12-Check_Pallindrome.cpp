#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str, int start, int end) {
    if(start >= end)
        return true;
    
    if(str[start] != str[end])
        return false;
    else
        return checkPalindrome(str, start+1, end-1);
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    getline(cin, str);

    if(checkPalindrome(str, 0, str.length()-1))
        cout << str << " is Palindrome!" << endl;
    else
        cout << str << " is not Palindrome!" << endl;

    cout << endl;
    return 0;
}