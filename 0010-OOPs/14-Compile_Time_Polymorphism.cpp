#include <bits/stdc++.h>
using namespace std;
//Compile-Time Polymorphism- Function & Operator Overloading

//Function Overloading
class Shape {
public:
    void area(int length, int breadth) {
        cout << "Area: " << length*breadth << endl;
    }
    void area(int side) {
        cout << "Area: " << side*side << endl;
    }
    void area(double radius) {
        cout << "Area: " << 3.141*radius*radius << endl;
    }
    static void functionOverloading() {
        Shape rectangle;
        rectangle.area(10, 20);

        Shape square;
        square.area(20);

        Shape circle;
        circle.area(10.0);
        cout << endl;
    }
};
class A {
public:
    int a, b;
    int add() {
        return a+b;
    }
//Operator Overloading
    void operator+ (A& obj1) {
        int value1= this->a;
        int value2= obj1.a;
        cout << "Overloaded Operator(+)\nOutput: " << value2-value1 << endl;
    }
    static void operatorOverloading() {
        A obj1;
        obj1.a= 5;
        A obj2;
        obj2.a= 3;
        obj2+obj1;
    }
};

int main() {
    system("cls");

    Shape::functionOverloading();
    A::operatorOverloading();

    cout << endl;
    return 0;
}