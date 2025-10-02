/*
Q. Print:-
        1111
         222
          33
           4
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
            cout << " ";
        for (int col = n - row + 1; col <= n; col++)
            cout << row;
        cout << endl;
    }

    system("pause>0");
    return 0;
}