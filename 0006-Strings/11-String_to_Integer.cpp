#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    bool isNegative = false;
    bool stringNotStarted = true;
    int ans = 0, n = s.length();

    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case ' ':
                if (!stringNotStarted)
                    i = n;
                break;
            case '+':
                if (stringNotStarted) {
                    isNegative = false;
                    stringNotStarted = false;
                } else
                    i = n;
                break;
            case '-':
                if (stringNotStarted) {
                    isNegative = true;
                    stringNotStarted = false;
                } else
                    i = n;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                if (stringNotStarted)
                    stringNotStarted = false;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                    return isNegative ? INT_MIN : INT_MAX;
                }
                ans = ans * 10 + (s[i] - '0');
                break;
            }
            default:
                i = n;
        }
    }
    return isNegative ? -ans : ans;
}

int main() {
    system("cls");

    string s;
    cout << "Enter String: ";
    getline(cin, s);

    int ans = myAtoi(s);
    cout << "Ans: " << ans << endl;

    cout << endl;
    return 0;
}
