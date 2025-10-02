#include <iostream>
#include <string>
using namespace std;

string reverseString(string str, int start, int end) {
    if(start >= end)
        return str;
    swap(str[start], str[end]);
    return reverseString(str, start+1, end-1);
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    getline(cin, str);

    cout << "Reverse String: " << reverseString(str, 0, str.length()-1) << endl;

    cout << endl;
    return 0;
}