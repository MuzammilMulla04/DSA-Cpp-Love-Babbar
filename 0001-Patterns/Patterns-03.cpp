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

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            cout << char('A' + n - col) << " ";
        }
        cout << endl;
    }

    system("pause>0");
    return 0;
}
