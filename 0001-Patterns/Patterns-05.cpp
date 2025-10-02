/*
Q. Print:-
        ****
         ***
          **
           *
*/

#include <iostream>
using namespace std;

int main() {
    system("cls");

    int n;

    cout << "Enter Number: ";
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row - 1; col++)
            cout << " ";
        for (int col = row; col <= n; col++)
            cout << "*";
        cout << endl;
    }

    system("pause>0");
    return 0;
}