#include <bits/stdc++.h> 
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    deque<int> maxElements;
    deque<int> minElements;
    long long int sum = 0;
    
    // For 1st Window
    for(int i = 0; i < k; i++) {
        // Remove elements from the back of the deque if they are less than the current element
        while(!maxElements.empty() && nums[maxElements.back()] <= nums[i])
            maxElements.pop_back();
        // Remove elements from the back of the deque if they are greater than the current element
        while(!minElements.empty() && nums[minElements.back()] >= nums[i])
            minElements.pop_back();

        maxElements.push_back(i);
        minElements.push_back(i);
    }
    
    // For Rest Windows
    for(int i = k; i < n; i++) {
        sum += nums[minElements.front()] + nums[maxElements.front()];
        
        // Remove elements if before the window
        while(!minElements.empty() && minElements.front() <= i - k)
            minElements.pop_front();
        while(!maxElements.empty() && maxElements.front() <= i - k)
            maxElements.pop_front();
        
        // Remove elements from the back of the deque if they are less than the current element
        while(!maxElements.empty() && nums[maxElements.back()] <= nums[i])
            maxElements.pop_back();
        // Remove elements from the back of the deque if they are greater than the current element
        while(!minElements.empty() && nums[minElements.back()] >= nums[i])
            minElements.pop_back();

        maxElements.push_back(i);
        minElements.push_back(i);
    }

    sum += nums[minElements.front()] + nums[maxElements.front()];
    return sum;    
}
