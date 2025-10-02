#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while(a != b) {
        if(a>b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    system("cls");

    int a, b;
    cout << "Enter two Numbers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;

    cout << endl;
    return 0;
}
