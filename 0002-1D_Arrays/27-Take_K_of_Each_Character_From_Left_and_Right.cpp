#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& freq, int k) {
        for(int& count: freq) {
            if(count < k)
                return false;
        }
        return true;
    }
public:
    int takeCharacters(string str, int k) {
        int n= str.size();
        vector<int> freq(3, 0);
        for(char& ch: str)
            freq[ch - 'a']++;

        if(!isPossible(freq, k))
            return -1;

        int ans= INT_MAX;
        int minutes= 0;
        int start= 0, end= 0;
        while(end < n) {
            freq[str[end] - 'a']--;
            end++;

            while(!isPossible(freq, k)) {
                freq[str[start] - 'a']++;
                start++;
            }

            minutes= n - (end - start);
            ans= min(ans, minutes);
        }

        return ans;
    }
};