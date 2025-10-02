#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        int pivotCount = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot)
                ans.push_back(nums[i]);
            if (nums[i] == pivot)
                ++pivotCount;
        }

        while (pivotCount--)
            ans.push_back(pivot);

        for (int i = 0; i < n; ++i) {
            if (nums[i] > pivot)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};