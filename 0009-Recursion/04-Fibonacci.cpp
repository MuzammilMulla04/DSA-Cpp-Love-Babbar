#include<iostream>
using namespace std;

int fibonacci(int n) {
    int a=0, b=1;
    for(int i=2; i<=n; i++) {
        (i%2 == 0)? a += b : b += a;
    }
    return (n%2 == 0)? a : b;
}
int fibonacciRecursion(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacciRecursion(n-1) + fibonacciRecursion(n-2);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Number is: " << fibonacciRecursion(n) << endl;

    cout << endl;
    return 0;
}