/*
Q. Print:-
           1
          23
         456
        78910
*/

#include <iostream>
using namespace std;

int main() {
    system("cls");

    int n;

    cout << "Enter Number: ";
    cin >> n;
    int count = 1;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n - row; col++)
            cout << " ";
        for (int col = n - row + 1; col <= n; col++) {
            cout << count;
            count++;
        }
        cout << endl;
    }

    system("pause>0");
    return 0;
}