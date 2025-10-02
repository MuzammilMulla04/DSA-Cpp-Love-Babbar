#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int start= 0, end= n-1;

        if(nums[end] < target)
            return n;
            
        while(start<end) {
            int mid= start + (end-start)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end= mid;
            else
                start= mid+1;
        }

        return start;
    }
};