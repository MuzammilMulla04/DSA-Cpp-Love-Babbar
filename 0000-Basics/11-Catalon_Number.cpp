#include <bits/stdc++.h>
using namespace std;

int catalonNumberApproach1(int n) {
    vector<int> catalon(n + 1, 0);
    catalon[0] = catalon[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++)
            catalon[i] += catalon[j] * catalon[i - j - 1];
    }

    return catalon[n];
}
int binomialCoefficient(int n, int r) {
    if (r > n - r)
        r = n - r;

    int result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
int catalonNumberApproach2(int n) {
    if (n == 0 || n == 1)
        return 1;

    return binomialCoefficient(2 * n, n) / (n + 1);
}
void catalonNumberApproach3(int n) {
    int result = 1;
    cout << result << " ";

    for (int i = 1; i < n; i++) {
        result *= (4 * i - 2) / (i + 1);
        cout << result << " ";
    }
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << endl;
/*
    for(int i=0; i<=n; i++)
        cout << catalonNumberApproach1(i) << " ";
*/
    // cout << n << "th Catalon Number: " << catalonNumberApproach2(n) << endl;

    cout << n << " Catalon Numbers: ";
    catalonNumberApproach3(n);
    cout << endl;

    cout << endl;
    return 0;
}