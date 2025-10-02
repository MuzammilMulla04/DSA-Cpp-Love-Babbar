#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n= a.length(), m= b.length();
        int i= n-1, j=m-1;

        string ans= "";
        int sum= 0, carry= 0;
        while(i >= 0 || j >= 0) {
            int val1= i>=0? a[i] - '0': 0;
            int val2= j>=0? b[j] - '0': 0;

            sum= val1 + val2 + carry;
            carry= sum/2;
            sum= sum%2;

            ans += sum + '0';
            i--;
            j--;
        }
        if(carry > 0)
            ans += '1';
        
        for(i= 0, j=ans.length()-1; i<j; i++, j--)
            swap(ans[i], ans[j]);
        
        return ans;
    }
};