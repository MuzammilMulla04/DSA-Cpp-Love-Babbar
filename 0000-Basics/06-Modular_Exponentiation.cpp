#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int ans=1;

    while(n>0) {
        if(n&1)
            ans *= (x%m);
        x= ((x%m) * (x%m))%m;
        n= n>>1;
    }
    return ans;
}

int main() {
    system("cls");

    int x, n, m;
    cout << "Enter Base: ";
    cin >> x;
    cout << "Enter Exponent: ";
    cin >> n;
    cout << "Enter Modulus: ";
    cin >> m;

    cout << x << "^" << n << "= " << modularExponentiation(x, n, m) << endl;

    cout << endl;
    return 0;
}
