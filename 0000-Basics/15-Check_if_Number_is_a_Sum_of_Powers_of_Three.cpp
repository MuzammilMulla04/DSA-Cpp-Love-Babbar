#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Keep checking the remainder when dividing by 3
        while (n > 0) {
            if (n % 3 == 2)  // If remainder is 2, return false
                return false;
            n /= 3;  // Reduce n by dividing it by 3
        }
        return true;  // If n is reduced to 0, return true
    }
};
