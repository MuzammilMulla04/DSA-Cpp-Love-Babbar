#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int power(int x, int n) {
    int ans = 1;
    cout << "X: " << x << endl;
    cout << "N: " << n << endl << endl;
    cout << "ANS: " << ans << endl;
    while (n > 0) {
        if (n & 1) {
            ans *= x;
            cout << "ANS: " << ans << endl;
        }
        x *= x;
        cout << "X: " << x << endl;
        n= n >> 1;
        cout << "N: " << n << endl << endl;
    }
    return ans;
}
int main() {
    system("cls");

    int x, n;
    cout << "Enter Base: ";
    cin >> x;
    cout << "Enter Exponent: ";
    cin >> n;

    cout << x << "^" << n << "= " << power(x, n) << endl;

    cout << endl;
    return 0;
}
