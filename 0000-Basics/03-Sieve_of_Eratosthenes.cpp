#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    int primeCount=0;
    vector<bool> prime(n+1, true);
    prime[0]= prime[1]= false;

    for(int i=2; i<n; i++) {
        if(prime[i]) {
            primeCount++;

            for(int j= 2*i; j<n; j += i)
                prime[j]= false;
        }
    } 
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
