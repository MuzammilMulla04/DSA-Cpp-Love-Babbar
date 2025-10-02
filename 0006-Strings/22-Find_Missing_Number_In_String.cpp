#include<bits/stdc++.h>
using namespace std;

int getFirstNum(string str) {
    int len;
    for(len=6 ;len>0; len--) {
        if(str[0] == str[len])
            break;
    }

    int num= 0;
    for(int i=0; i<len; i++) {
        int digit= str[i] - '0';
        num *= 10;
        num += digit;
    }

    return num;
}
string missingNumber(string str) {
// Get first Number from string
    int num= getFirstNum(str);
    int len= 0;
    for(int temp= num; temp>0; temp /= 10)
        len++;
// Use it as counter to traverse string
    int n= str.size();
    int i=0;
    string ans= "-1";
    int flag= 0;
    while(i<n) {
        string curr= to_string(num);

        for(char& ch: curr) {
            if(ch != str[i]) {
                flag++;
                ans= to_string(num);
            }
            i++;
        }

        num++;
    }
    //if no missing --> -1
    //if 1 missing --> (string)missingNumber
    //if >1 missing --> -1
    return flag == 1? ans: "-1";
}