#include<iostream>
using namespace std;

void printCounting(int n) {
    if(n == 0) {
        cout << endl;
        return;
    }
    cout << n << " ";
    printCounting(n-1);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    printCounting(n);

    cout << endl;
    return 0;
}