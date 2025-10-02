#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lis(vector<int>& arr) {
        vector<int> lis;  // This vector stores the smallest possible LIS sequence dynamically

        for (int num : arr) {
            // Find the first element in 'lis' that is >= 'num' using binary search (lower_bound)
            auto it = lower_bound(lis.begin(), lis.end(), num);

            if (it == lis.end()) {
                // If 'num' is greater than all elements in 'lis', extend the sequence
                lis.push_back(num);
            } else {
                // Otherwise, replace the first element that is >= 'num' to maintain the smallest LIS
                *it = num;
            }
        }
        return lis.size();  // The size of 'lis' represents the length of the Longest Increasing Subsequence
    }
};
