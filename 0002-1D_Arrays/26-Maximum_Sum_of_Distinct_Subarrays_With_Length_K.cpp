#include<bits/stdc++.h>
using namespace std;

// 1.
class Solution {
    void debug(int num, queue<int> q, unordered_map<int, int> freq, long long sum, long long ans) {
        cout << "num= " << num  << endl << "sum= " << sum << endl << "ans= " << ans << endl;
        cout << "q: ";
        while(!q.empty()) {
            int front= q.front();
            q.pop();

            cout << front << " ";
        }
        cout << endl;

        cout << "freq: ";
        for(auto& pair: freq) {
            cout << pair.first << ":" << pair.second << ", ";
        }
        cout << endl << endl;
    }
    bool isDistinct(unordered_map<int, int>& freq) {
        for(auto& pair: freq) {
            if(pair.second > 1)
                return false;
        }
        return true;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        long long ans= 0;

        queue<int> q;
        long long sum= 0;
        unordered_map<int, int> freq;
        for(int& num: nums) {
            if(q.size() < k) {
                q.push(num);
                sum += num;
                freq[num]++;
            } else {
                if(isDistinct(freq))
                    ans= max(ans, sum);

                int front= q.front();
                q.pop();
                sum -= front;
                freq[front]--;

                q.push(num);
                sum += num;
                freq[num]++;
            }

            // debug(num, q, freq, sum, ans);
        }

        return isDistinct(freq)? max(ans, sum): ans;
    }
};

// 2.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        long long sum= 0, ans= 0;
        unordered_map<int, int> freq;
        int duplicateCount= 0;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            freq[nums[i]]++;

            if(freq[nums[i]] == 2)
                duplicateCount++;
            
            if(i >= k) {
                int left= nums[i - k];
                sum -= left;
                if(freq[left] == 2)
                    duplicateCount--;
                freq[left]--;
            }

            if(i >= k-1 && duplicateCount == 0)
                ans= max(ans, sum);
        }

        return duplicateCount == 0? max(ans, sum): ans;
    }
};