#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0) return false;

        // Check divisibility for odd numbers up to sqrt(num)
        for (int div = 3; div * div <= num; div += 2) {
            if (num % div == 0) return false;
        }
        return true;
    }

public:
    std::vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDiff = INT_MAX;

        for (int num = left; num <= right; num++) {
            if (isPrime(num)) {
                if (prevPrime != -1) {
                    int diff = num - prevPrime;

                    // Update closest pair if a smaller difference is found
                    if (diff < minDiff) {
                        minDiff = diff;
                        closestA = prevPrime;
                        closestB = num;
                    }

                    // Twin prime optimization: If difference is 2 or 1, return immediately
                    if (diff == 2 || diff == 1) return {prevPrime, num};
                }
                prevPrime = num;
            }
        }
        return (closestA == -1) ? std::vector<int>{-1, -1} : std::vector<int>{closestA, closestB};
    }
};