#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n= nums.size();
        int goodPairs= 0;

        for(int i=0; i<n; i++) {
            for(int j= i+1; j<n; j++) {
                if(nums[i] == nums[j])
                    goodPairs++;
            }
        }
        
        return goodPairs;
    }
};

// Approach 2: NCR method
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<char, int> count;

        for(int i: nums)
            count[i]++;
        
        int goodPairs= 0;
        for(auto pair: count)   // Since NC2= n(n-1)/2
            goodPairs  += pair.second*(pair.second-1)/2;

        return goodPairs;
    }
};
