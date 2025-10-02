#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> frequency;

    int maxFreq= INT_MIN;
    for(int i=0; i<n; i++) {
        frequency[arr[i]]++;
        maxFreq= max(maxFreq, frequency[arr[i]]);
    }

    int maxNum= -1;
    for(auto data: arr) {
        if(maxFreq == frequency[data]) {
            maxNum= data;
            break;
        }
    }

    return maxNum;
}