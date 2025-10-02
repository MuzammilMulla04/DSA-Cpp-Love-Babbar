#include<iostream>
#include<limits>
#include<vector>
#include<unordered_amp>

// 1. Using Unordered Map & minHeap
class Solution1 {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& num: nums)
            freq[num]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& pair: freq) {
            const int& num= pair.first;
            minHeap.push(num);

            while(minHeap.size() > 3) {
                minHeap.pop();
            }
        }

        if(minHeap.size() < 3) {
            int max;

            while(!minHeap.empty()) {
                max= minHeap.top();
                minHeap.pop();
            }

            return max;
        } else {
            return minHeap.top();
        }
    }
};

// 2. Using Map
class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int> freq;
        for(int& num: nums)
            freq[num]++;

        auto it= freq.rbegin();

        if(freq.size() < 3) {            
            return it->first;
        } else {
            it++;
            it++;
            return it->first;
        }
    }
};

// 3. using Set
class Solution3 {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int& num: nums) {
            s.insert(num);

            if(s.size() > 3) {
                s.erase(s.begin());
            }
        }

        if(s.size() < 3) {
            return *prev(s.end());
        } else {
            return *s.begin();
        }
    }
};

// 4. Constant Space (If-Else)
class Solution4 {
public:
    int thirdMax(vector<int>& nums) {
        vector<long> arr(3, LONG_MIN);
        // [max_1, max_2, max_3]

        for(int& num: nums) {
            if(num == arr[0] || num == arr[1] || num == arr[2])
                continue;

            if(num > arr[0]) {
                arr[2]= arr[1];
                arr[1]= arr[0];
                arr[0]= num;
            } else if(num > arr[1]) {
                arr[2]= arr[1];
                arr[1]= num;
            } else if(num > arr[2]) {
                arr[2]= num;
            }
        }

        return arr[2] == LONG_MIN? arr[0]: arr[2];
    }
};
