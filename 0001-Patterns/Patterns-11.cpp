/*
Q. Print:-
        1234554321
        1234**4321
        123****321
        12******21
        1********1
*/

#include <iostream>
using namespace std;

int main() {
    system("cls");

    int n;

    cout << "Enter Number: ";
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n - row + 1; col++)
            cout << col;
        for (int col = 1; col <= row - 1; col++)
            cout << "**";
        for (int col = n - row + 1; col >= 1; col--)
            cout << col;
        cout << endl;
    }

    system("pause>0");
    return 0;
}