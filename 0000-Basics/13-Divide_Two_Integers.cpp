#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getNoOfBits(int n) {
        return log(n)/log(2) + 1;
    }
    void getBinary(int num, int size, vector<bool>& binary) {
        bitset<32> b(num);
        
        for(int i=0, gap= 32-size; i<size; i++)
            binary[i]= b[i+gap];
    }


    void restoringDivision(vector<bool>& dividend, vector<bool>& divisor) {
        

    }

public:
    int divide(int dividend, int divisor) {
        int n= getNoOfBits(dividend);

        vector<bool> Q(n+1, 0);
        vector<bool> M(n+1, 0);
        vector<bool> A(n+1, 0);

        getBinary(dividend, n+1, Q);
        getBinary(divisor, n+1, M);

        
    }
};

int main() {
    system("cls");

    Solution s;
    s.divide(10, 2);

    cout << endl;
    return 0;
}