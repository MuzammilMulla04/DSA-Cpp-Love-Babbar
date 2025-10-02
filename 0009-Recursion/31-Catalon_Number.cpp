#include<bits/stdc++.h>
using namespace std;

int catalonNumber(int n) {
    if(n <= 1)
        return 1;
    
    int result=0;
    for(int i=0; i<n; i++)
        result += catalonNumber(i)*catalonNumber(n-i-1);

    return result;
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << endl;
    for(int i=0; i<=n; i++)
        cout << catalonNumber(i) << " ";
        // cout << n << "th Catalon Number: " << catalonNumber(n) << endl;
    cout << endl;

    cout << endl;
    return 0;
}