#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // First pass: Apply transformation
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        // Second pass: Move non-zero elements forward
        int insertPos = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insertPos]);
                ++insertPos;
            }
        }

        return nums;
    }
};
