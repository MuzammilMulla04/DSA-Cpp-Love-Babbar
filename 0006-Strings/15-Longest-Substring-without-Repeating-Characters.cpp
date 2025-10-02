#include <bits/stdc++.h>
using namespace std;

// Approach 1
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> count;
        queue<char> q;
        int maxSize= 0;
        int size= 0;

        for(char ch: str) {
            if(count[ch] > 0) {
                while(size>0 && q.front() != ch) {
                    char front= q.front();
                    count[front]= count[front] == 0? 0: count[front]-1;
                    q.pop();
                    size--;
                }

                if(size>0) {
                    char front= q.front();
                    count[front]= count[front] == 0? 0: count[front]-1;
                    q.pop();
                    size--;
                }
            }

            q.push(ch);
            count[ch]++;
            size++;
            maxSize= max(maxSize, size);
        }

        return maxSize;
    }
};

// Approach 2
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n= str.size();
        unordered_map<char, int> count;
        int start= 0, length= 0, maxLength= 0;

        for(char ch: str) {
            if(count[ch] > 0) {
                while(start<n && str[start] != ch) {
                    count[str[start]]= count[str[start]] == 0? 0: count[str[start]]-1;
                    start++;
                    length--;
                }

                if(start<n) {
                    count[str[start]]= count[str[start]] == 0? 0: count[str[start]]-1;
                    start++;
                    length--;
                }
            }

            count[ch]++;
            length++;
            maxLength= max(maxLength, length);
        }

        return maxLength;
    }
};

