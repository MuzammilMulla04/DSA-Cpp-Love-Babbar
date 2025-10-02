#include<iostream>
using namespace std;

int getLength(char arr[]) {
    int count=0;
    for(int i=0; arr[i] != '\0'; i++)
        count++;
    return count;
}
void reverseCharArray(char arr[]) {
    for(int i=0, j=getLength(arr)-1; i<j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}
char toLowerCase(char c) {
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
}
bool validCharacter(char ch) {
    if(ch >= 'A' && ch <= 'Z')
        return true;
    else if(ch >= 'a' && ch <= 'z')
        return true;
    else if(ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}
bool checkIfPallindrome(char arr[]) {
    for(int i=0, j=getLength(arr)-1; i<j; ) {
        if(!validCharacter(arr[i]))
            i++;
        else if(!validCharacter(arr[j]))
            j--;
        else {
            if(arr[i++] != arr[j--])
                return false;
        }
    }
    return true;
}

int main() {
    system("cls");

    char name[20];
    cout << "Enter your name: ";
    cin >> name;

    if(checkIfPallindrome(name))
        cout << name << " is Pallindrome!" << endl;
    else
        cout << name << " is not Pallindrome!" << endl;

    cout << endl;
    return 0;
}