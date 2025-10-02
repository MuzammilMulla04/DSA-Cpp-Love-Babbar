#include <iostream>
#include <string>
using namespace std;

int exponent(int x, int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n&1)
        return x * exponent(x, n/2) * exponent(x, n/2);
    else
        return exponent(x, n/2) * exponent(x, n/2);
        
}

int main() {
    system("cls");

    int x, n;

    cout << "Enter Base: ";
    cin >> x;
    cout << "Enter Power: ";
    cin >> n;

    cout << x << "^" << n  << "= " << exponent(x, n) << endl;

    cout << endl;
    return 0;
}