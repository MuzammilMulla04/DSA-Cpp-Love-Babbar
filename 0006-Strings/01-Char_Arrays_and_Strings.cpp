#include<iostream>
#include<string>
using namespace std;

int main() {
    system("cls");

    char name[20];
    cout << "Enter your name: ";
    cin.getline(name, 20);
    cout << "Your name is: " << name << endl;
    cout << endl;

    string str;
    cout << "Enter String: ";
    getline(cin, str, '\n');
    cout << "String: " << str << endl;
    cout << endl;

    char array[]= "ab\0cd\0";
    cout << "Char Array: " << array << endl;
    string s= "ab\0cd\0";
    cout << "String: " << s << endl;


    cout << endl;
    return 0;
}