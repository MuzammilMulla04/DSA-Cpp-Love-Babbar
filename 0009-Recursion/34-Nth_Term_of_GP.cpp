#include <bits/stdc++.h>
using namespace std;

long long int modularExponentiation(long long int x, int n, int m) {
    long long int ans= 1;

    while(n>0) {
        if(n&1)
            ans= (ans*x)%m;
        x= (x*x)%m;
        n= n>>1;
    }

    return ans;
}
int nthTermOfGP(int N, int A, int R) {
    const int mod= 1e9 + 7;
    long long int ans= (long long int)A * modularExponentiation(R, N-1, mod);
    return ans%mod;
}
