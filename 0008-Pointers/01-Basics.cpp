#include<iostream>
using namespace std;

int main() {
    system("cls");

    int num=5;
    cout << "Num: " << num << endl;
    cout << "Address of Num: " << &num << endl;
    cout << endl;

    int *ptr= &num;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << endl;

    double d=4.3;
    cout << "d: " << d << endl;
    double *ptr2= &d;
    cout << "ptr2: " << ptr2 << endl;
    cout << "*ptr2: " << *ptr2 << endl;
    cout << endl;
   
    double i=10;
    // int *p; --Bad Practice!
    double *p=0;
    cout << p << endl; //Segmentation Fault- Accessing a memory which doesn't exist
    p= &i;
    cout << "Size of i: " << sizeof(i) << endl;
    cout << "Size of *p: " << sizeof(*p) << endl;
    cout << "Size of p: " << sizeof(p) << endl;
    cout << endl;

    int a=15;
    int *ptr3= &a;
    int b= *ptr3;
    a++;
    cout << "a: " << a << endl;
    cout << "*ptr3: " << *ptr3 << endl;
    cout << "b: " << b << endl;
    cout << endl;

    int c=35;
    int *ptr4= &c;
    cout << "c Before : " << c << endl;
    (*ptr4)++;
    cout << "c After : " << c << endl;
    cout << endl;

    int g=110;
    int *p1= &g;
    int *p2= p1;
    cout << p1 << "-" << p2 << endl;
    cout << *p1 << "-" << *p2 << endl;
    cout << endl;

    int t=52;
    int *ptrt= &t;
    cout << "t: " << t << endl;
    cout << "*ptrt: " << *ptrt << endl;
    (*ptrt)= (*ptrt)+1; //*ptrt++
    cout << "t: " << t << endl;
    cout << "*ptrt: " << *ptrt << endl;
    cout << "Before ptrt: " << ptrt << endl; //0x61fec8
    ptrt= ptrt+1; // ptrt++
    cout << "Before ptrt: " << ptrt << endl; //0x61fec8 + sizeof(int)= 0x61fecc

    cout << endl;
    return 0;
}