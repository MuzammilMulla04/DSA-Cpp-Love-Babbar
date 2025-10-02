#include<iostream>
using namespace std;

inline int getMax(int &a, int &b) {
    return (a>b)? a:b;
}

int main() {
    system("cls");

    int a=1, b=2, ans;
    ans= getMax(a, b);
    cout << ans << endl;

    a += 5;
    b += 3;
    ans= getMax(a, b);
    cout << ans << endl;

    cout << endl;
    return 0;
}