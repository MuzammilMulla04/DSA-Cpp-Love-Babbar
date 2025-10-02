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
int main() {
    system("cls");

    char name[20];
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is: " << name << endl;
    cout << "Length of your name is: " << getLength(name) << endl;
    reverseCharArray(name);
    cout << "Reverse of your name is: " << name << endl;

    cout << endl;
    return 0;
}