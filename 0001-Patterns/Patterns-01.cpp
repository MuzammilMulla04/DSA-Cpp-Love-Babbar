/*
Q. Print:-
        1
        23
        345
        4567
        56789...
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
            cout << row + col - 1 << " ";
        }
        cout << endl;
    }

    system("pause>0");
    return 0;
}
