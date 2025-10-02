#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    string name;
    string voice;
    void bark() {
        cout << name << "-" << voice << endl;
    }
};
//Single Inheritance
class Dog: public Animal {};
//Multi-level Inheritance
class germanShepherd: public Dog {};
//Multiple Inheritance
class Human {
public:
    string gender;
    void speak() {
        cout << gender << "-" << "speaks!" << endl;
    }
};
class Hybrid: public Animal, public Human {};
//Heirarchical Inheritance
class A {
public:
    void function1() {
        cout << "In Function 1!" << endl;
    }
};
class B: public A {
public:
    void function2() {
        cout << "In Function 2!" << endl;
    }
};
class C: public A {
public:
    void function3() {
        cout << "In Function 3!" << endl;
    }
};
//Hybrid Inheritance- combination of any above Inheritances 

int main() {
    system("cls");

    germanShepherd g;
    g.name= "Lan";
    g.voice= "Bow!";
    g.bark();
    cout << endl;

    Hybrid h;
    h.gender= "Male";
    h.speak();
    cout << endl;

    A obj1;
    obj1.function1();
    B obj2;
    obj2.function1();
    obj2.function2();
    C obj3;
    obj3.function1();
    obj3.function3();
    cout << endl;

    cout << endl;
    return 0;
}