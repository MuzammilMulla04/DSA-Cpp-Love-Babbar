#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(n<2)
        return false; 
    for(int i=2; i<n; i++) {
        if(n%i == 0)
            return false;
    }
    return true;    
}
int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    if(isPrime(n))
        cout << n << " is Prime!" << endl;
    else
        cout << n << " is not Prime!" << endl;

    cout << endl;
    return 0;
}
