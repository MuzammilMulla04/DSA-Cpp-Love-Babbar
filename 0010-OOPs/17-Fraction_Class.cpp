#include <bits/stdc++.h> 
using namespace std;

class Fraction {
public:
    int n, d;
//Constructor
    Fraction(int n, int d): n(n), d(d) {}
//Functions
    void add(const Fraction& f2) {
        int ansN= n*f2.d + d*f2.n;
        int ansD= d*f2.d;

        n= ansN;
        d= ansD;

        simplify();
    }
    void multiply(const Fraction& f2) {
        int ansN= n*f2.n;
        int ansD= d*f2.d;

        n= ansN;
        d= ansD;

        simplify();
    }
    void simplify() {
        int gcd= __gcd(n, d);
        n /= gcd;
        d /= gcd;
    }
    void print() {
        cout << n << "/" << d << endl;
    }
};

int main() {
    system("cls");

    int n, d;
    cin >> n >> d;
    Fraction f1(n, d);

    int noOfOperations;
    cin >> noOfOperations;

    for(int i=0; i<noOfOperations; i++) {
        int typeOfOperation;
        cin >> typeOfOperation >> n >> d;
        Fraction f2(n, d);

        switch(typeOfOperation) {
            case 1: {// Addition
                f1.add(f2);
                break;
            }
            case 2: {// Multiplication
                f1.multiply(f2);
                break;
            }
        }

        f1.print();
    }

    return 0;
}