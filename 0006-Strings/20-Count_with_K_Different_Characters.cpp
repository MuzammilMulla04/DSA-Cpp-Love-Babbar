#include<bits/stdc++.h>
using namespace std;

int countSubStrings(string str, int k) {
    int n= str.size();
    unordered_map<char, int> freq;
    int distinctCount= 0;
    int ans= 0;

    int i=0, j=0;
    while(distinctCount<k) {
        if(freq[str[i]] == 0)
            distinctCount++;
        freq[str[i]]++;
        i++;
    }

    while(i<n) {
        if(distinctCount == k)
            ans++;

        if(distinctCount > k) {
            freq[str[j]]--;
            if(freq[str[j]] == 0)
                distinctCount--;
            j++;
        } else {
            if(freq[str[i]] == 0)
                distinctCount++;
            freq[str[i]]++;
            i++;                        
        }
    }

    return ans;
}
