#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string str) {
        unordered_map<char, int> count;
        queue<char> q;

        string ans= "";
        int n= str.length();

        for(int i=0; i<n; i++) {
            char ch= str[i];
            count[ch]++;

            q.push(ch);

            while(!q.empty()) {
                ch= q.front();
                if(count[ch] > 1) {
                    q.pop();
                } else {
                    ans.push_back(ch);
                    break;
                }
            }

            if(q.empty()) {
                ans.push_back('#');
            }
        }

        return ans;
    }
};