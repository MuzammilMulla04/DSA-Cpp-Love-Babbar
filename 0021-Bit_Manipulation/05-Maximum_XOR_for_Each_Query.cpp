#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int Xor= 0;
        for(const int& num: nums)
            Xor ^= num;

        int maxNum= pow(2, maximumBit) - 1;
        vector<int> ans;

        for(int q= nums.size(); q > 0; q--) {
            int k= maxNum ^ Xor;
            ans.push_back(k);

            Xor ^= nums[q-1];
            nums.pop_back();
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxNum= (1LL << maximumBit) - 1, n= nums.size();
        vector<int> ans(n);
        for(int i= 0, Xor= 0; i<n; i++) {
            Xor ^= nums[i];
            ans[n-i-1]= maxNum ^ Xor;
        }
        return ans;
    }
};