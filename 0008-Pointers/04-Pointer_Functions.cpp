#include<iostream>
using namespace std;

void printPointer(int *p) {
    cout << p << endl;
}
void printPointerContent(int *p) {
    cout << *p << endl;
}
void updatePointer(int *p) {
    p= p+1;
}
void updatePointerContent(int *p) {
    *p= *p+1;
}

int getSum(int arr[], int n) {
//  int getSum(int *arr, int n) {       //  Internally
    cout << "sizeof(arr) in function: " << sizeof(arr) << endl;
    int sum=0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    return sum;
}

int main() {
    system("cls");

    int value= 5;
    int *p= &value;

    cout << "p before: ";
    printPointer(p);
    updatePointer(p);
    cout << "p after: ";
    printPointer(p);
    cout << endl;

    cout << "p before: ";
    printPointerContent(p);
    updatePointerContent(p);
    cout << "p after: ";
    printPointerContent(p);
    cout << endl;

    int arr[5]= {1, 2, 3, 4, 5};
    cout << "sizeof(arr) before function: " << sizeof(arr) << endl;
    cout << "Sum: " << getSum(arr, 5) << endl;
    cout << endl;

    cout << "Sum of partial array: " << getSum(arr+2, 5-2);


    cout << endl;
    return 0;
}