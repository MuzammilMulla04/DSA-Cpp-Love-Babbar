#include<iostream>
using namespace std;

void print(int **p) {
    cout << "p2: " << p << endl;
    cout << "p: " << *p << endl;
    cout << "i: " << **p << endl;
    cout << endl;
}
void update(int **p) {
    //p= p+1;       //NO, none
    //*p= *p+1;     //YES, p & i
    **p= **p+1;     //YES, only i
}

int main() {
    system("cls");

    int i=5;
    int *p= &i;
    int **p2= &p;

    cout << "i: " << i << endl;
    cout << "*p: " << *p << endl;
    cout << "**p2: " << **p2 << endl;
    cout << endl;

    cout << "&i: " << &i << endl;
    cout << "p: " << p << endl;
    cout << "*p2: " << *p2 << endl;
    cout << endl;

    cout << "&p: " << &p << endl;
    cout << "p2: " << p2 << endl;
    cout << endl;

    print(p2);
    update(p2);
    print(p2);

    cout << endl;
    return 0;
}