#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        bool flag= false;

        int index=0, i=1;
        while(i<n) {
            if(nums[i-1] == nums[i] && flag) {
                i++;
                flag= !flag;
            } else {
                nums[index]= nums[i];
                index++;
                i++;
                flag= !flag;
            }
        }

        return index;
    }
};