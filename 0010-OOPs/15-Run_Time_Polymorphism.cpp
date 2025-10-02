#include <bits/stdc++.h>
using namespace std;
//Run-Time Polymorphism- Function Over-riding

//Function Over-riding
class Rectangle {
public:
    int length;
    int breadth;
    Rectangle(int length, int breadth) {
        this->length= length;
        this->breadth= breadth;
    }
    void area() {
        cout << "Area: " << this->length * this->breadth << endl;
    }
    static void areaOfRectangle() {
        Rectangle r= Rectangle(10, 20);
        r.area();
    }
};
class Square: public Rectangle {
public:
    int side;
    Square(int side): Rectangle(length, breadth) {
        this->side= side;
    }
    void area() {
        cout << "Area: " << this->side*this->side << endl;
    }
    static void areaOfSquare() {
        Square s(20);
        s.area();
    }
};

int main() {
    system("cls");

    Rectangle::areaOfRectangle();
    Square::areaOfSquare();

    cout << endl;
    return 0;
}