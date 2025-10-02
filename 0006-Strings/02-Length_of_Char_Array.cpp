#include<iostream>
using namespace std;

int getLength(char arr[]) {
    int count=0;
    for(int i=0; arr[i] != '\0'; i++)
        count++;
    return count;
}

int main() {
    system("cls");

    char name[20];
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is: " << name << endl;
    cout << "Length of your name is: " << getLength(name) << endl;

    cout << endl;
    return 0;
}