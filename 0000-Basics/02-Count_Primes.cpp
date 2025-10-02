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
int countPrimes(int n) {
    int primeCount=0;
    cout << endl;
    for(int i=2; i<n; i++) {
        if(isPrime(i)) {
            primeCount++;
            cout << i << " ";
        }
    }
    cout << endl;
    return primeCount;
}
int main() {
    system("cls");

    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "There are " << countPrimes(n) << " Primes before " << n << endl;

    cout << endl;
    return 0;
}
