#include<iostream>
using namespace std;

void WhatIsReferenceVariable() {
    int i=5;
    int& j=i;

    cout << i << endl;
    cout << j << endl;
    cout << endl;

    i++;
    cout << i << endl;
    cout << j << endl;
    cout << endl;
    
    j++;
    cout << i << endl;
    cout << j << endl;
    cout << endl;
}
void passByReference(int& a) {
// int& returnByReference(int a) {     // Bad Practice!
    a++;
}
void functionUsingReferenceVariable() {
    int a=5;
    cout << "a before: " << a << endl;
    passByReference(a);
    cout << "a after: " << a << endl;
}

int main() {
    system("cls");

    WhatIsReferenceVariable();
    functionUsingReferenceVariable();
    
    cout << endl;
    return 0;
}