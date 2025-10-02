#include<iostream>
using namespace std;

int main() {
    system("cls");

    int arr[]= {2, 5, 6};

    cout << "arr: " << arr << endl;
    cout << "&arr[0]: " << &arr[0] << endl;
    cout << endl;

    cout << "arr[0]: " << arr[0] << endl;
    cout << "*arr: " << *arr << endl;
    cout << endl;

    cout << "arr[0] + 1: " << arr[0] + 1 << endl;
    cout << "*arr + 1: " << *arr + 1 << endl;
    cout << endl;

    cout << "arr[(0+1)]: " << arr[(0+1)] << endl;
    cout << "*(arr + 1): " << *(arr + 1) << endl;
    cout << endl;

    // arr[i]= *(arr+i)
    // *(arr+i)= *(i+arr)= i[arr]
    // arr[i]= i[arr]

    cout << "arr[2]: " << arr[2] << endl;
    cout << "2[arr]: " << 2[arr] << endl;
    cout << endl;

    int temp[10]= {1, 2};
    int *ptr= &temp[0];
    cout << "temp: " << temp << endl;
    cout << "ptr: " << ptr << endl;
    cout << "*temp: " << *temp << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "&temp: " << &temp << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << endl;

    cout << "sizeof(temp): " << sizeof(temp) << endl;
    cout << "sizeof(ptr): " << sizeof(ptr) << endl;
    cout << "sizeof(*temp): " << sizeof(*temp) << endl;
    cout << "sizeof(*ptr): " << sizeof(*ptr) << endl;
    cout << "sizeof(&temp): " << sizeof(&temp) << endl;
    cout << "sizeof(&ptr): " << sizeof(&ptr) << endl;
    cout << endl;

    int a[10];
    //a=a+1;    //ERROR, Cannot change mapping of Symbol Table
    int *p1= a;
    cout << "OLD p1: " << p1 << endl;
    p1++;
    cout << "NEW p1: " << p1 << endl;

    cout << endl;
    return 0;
}