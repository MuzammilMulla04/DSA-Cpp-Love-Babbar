#include<iostream>
using namespace std;

int factorial(int n) {
//Base Case/Condition
    if(n == 0)
        return 1;
    int smallerProblem= factorial(n-1);
    int biggerProblem= n*smallerProblem;    //Recurrence/recursive Relation
    return biggerProblem;
}
int optimizedFactorial(int n) {
    if(n == 0)
        return 1;
    return n*optimizedFactorial(n-1);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Factorial of " << n << " is: " << optimizedFactorial(n) << endl;

    cout << endl;
    return 0;
}