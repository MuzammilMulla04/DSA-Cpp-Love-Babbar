#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD= 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int count= 0, prefixSum= 0;
        int oddCount= 0, evenCount= 1;

        for(const int& num: arr) {
            prefixSum += num;
            
            // If prefix sum is even, add odd subarrays
            if(prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                // If prefix sum is odd, add even subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD;
        }

        return count;
    }
};