#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1) {
            return x;
        } else if(n == 0) {
            return 1;
        }

        long double y= x;
        long double ans= 1;
        if(n > 0) {
            while(n > 0) {
                if(n&1) {
                    ans *= y;
                }
                y *= y;
                n= n>>1;
            }
        } else {
            n= abs(n);
            while(n > 0) {
                if(n&1) {
                    ans /= y;
                }
                y *= y;
                n= n>>1;
            }
        }

        return ans;
    }
};

int main() {
    system("cls");

    double x;
    int n;

    cout << "Enter Base: ";
    cin >> x;

    cout << "Enter Exponent: ";
    cin >> n;

    Solution s;
    cout << x << "^" << n << "= " << s.myPow(x, n) << endl;

    return 0;
}