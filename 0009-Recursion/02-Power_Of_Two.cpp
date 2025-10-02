#include<iostream>
using namespace std;

int powerOf2(int n) {
    if(n == 0)
        return 1;
    return 2*powerOf2(n-1);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "2^" << n << ": " << powerOf2(n) << endl;

    cout << endl;
    return 0;
}