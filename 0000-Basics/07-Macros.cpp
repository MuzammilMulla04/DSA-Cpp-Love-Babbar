#include<iostream>
using namespace std;

#define PI 3.141
#define area(r) PI*r*r

int main() {
    system("cls");

    double r;
    cout << "Enter Radius: ";
    cin >> r;

    cout << "Area of Circle: " << area(r) << endl;

    cout << endl;
    return 0;
}