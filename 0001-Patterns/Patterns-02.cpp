/*
Q. Print:-
        123
        234
        345...
*/

#include <iostream>
using namespace std;

int main() {
    system("cls");

    int n;

    cout << "Enter Number: ";
    cin >> n;

    for (int row = 1 + 'A' - 1; row <= n + 'A' - 1; row++) {
        for (int col = 1; col <= n; col++) {
            cout << char(row + col - 1) << " ";
        }
        cout << endl;
    }

    system("pause>0");
    return 0;
}
