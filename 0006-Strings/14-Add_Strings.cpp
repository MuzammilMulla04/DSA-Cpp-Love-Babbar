#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str) {
    int n= str.length();
    for(int i=0, j=n-1; i<j; i++, j--) {
        swap(str[i], str[j]);
    }
}
string stringSum(string &num1, string &num2) {
    int i=num1.length()-1, j=num2.length()-1;
    int sum=0, carry=0;
    string ans= "";

    while(i>=0 || j>=0) {
        int val1= (i>=0)? (num1[i]- '0'): 0;
        int val2= (j>=0)? (num2[j]- '0'): 0;

        sum= val1 + val2 + carry;
        
        carry= sum/10;
        sum %= 10;

        ans += sum + '0';
        i--;
        j--;
    }

    if(carry != 0) {
        ans += carry + '0';
    }

    reverseString(ans);
    return ans;    
}