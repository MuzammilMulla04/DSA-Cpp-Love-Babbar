#include<iostream>
using namespace std;

int i=5;

void a() {
    i++;
}
void b() {
    i+=2;
}
void c() {
    i+=3;
}

int main() {
    system("cls");

    cout << i << endl;
    a();
    cout << i << endl;
    b();
    cout << i << endl;
    c();
    cout << i << endl;


    cout << endl;
    return 0;
}