#include <iostream>
#include <string>
using namespace std;

void sayDigits(int n) {
    string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n == 0)
        return;
    sayDigits(n / 10);
    int digit = n % 10;
    cout << map[digit] << " ";
}

int main() {
    system("cls");

    int number;
    cout << "Enter Number: ";
    cin >> number;

    sayDigits(number);

    cout << endl;
    return 0;
}