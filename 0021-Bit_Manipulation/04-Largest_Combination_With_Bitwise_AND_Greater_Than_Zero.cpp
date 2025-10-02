#include<bits/stdc++.h>
using namespace std;

// 1. Recusrion
class Solution {
    int solve(vector<int>& candidates, int index, int bitAND, int size) {
        if(index >= candidates.size()) {
            return bitAND > 0? size: 0;
        }

        int exclude= solve(candidates, index+1, bitAND, size);

        bitAND &= candidates[index];
        size++;
        int include= solve(candidates, index+1, bitAND, size);

        return max(exclude, include);
    }

public:
    int largestCombination(vector<int>& candidates) {
        return solve(candidates, 0, INT_MAX, 0);
    }
};

// 2. Bit Manipulation
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans= 0;
        for(int bit= 0; bit < 32; bit++) {
            int count= 0;
            for(const int& candidate: candidates) {
                if(candidate & (1 << bit))
                    count++;
            }
            ans= max(count, ans);
        }
        return ans;
    }
};