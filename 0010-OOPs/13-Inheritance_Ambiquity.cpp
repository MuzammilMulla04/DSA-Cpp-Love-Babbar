#include <bits/stdc++.h>
using namespace std;

class A {
public:
    void function() {
        cout << "Function of Class A!" << endl;
    }
};
class B {
public:
    void function() {
        cout << "Function of Class B!" << endl;
    }
};
class C: public A, public B {};

int main() {
    system("cls");

    C obj;
    // obj.function();      //????

    obj.A::function();
    obj.B::function();

    cout << endl;
    return 0;
}