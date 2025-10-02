#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int>& arr, int target, int n) {
    unordered_map<int, int> freq;
    vector<pair<int, int>> ans;
    
    // Count the frequency of each element in the array
    for (int num : arr) {
        freq[num]++;
    }
    
    // Find pairs
    for (int& num : arr) {
        int complement = target - num;
        
        // Check if the complement exists in the map
        if (freq[complement] > 0) {
            // If num and complement are the same, ensure there are at least two instances
            if (num == complement) {
                if (freq[num] > 1) {
                    ans.push_back({num, complement});
                    freq[num] -= 2;
                }
            } else if (freq[num] > 0 && freq[complement] > 0) {
                ans.push_back({num, complement});
                freq[num]--;
                freq[complement]--;
            }
        }
    }
    
    // If no pairs are found, return {-1, -1}
    if (ans.empty()) {
        ans.push_back({-1, -1});
    }
    
    return ans;
}