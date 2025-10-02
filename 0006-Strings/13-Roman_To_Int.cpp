#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class SolutionMap {
public:
    int romanToInt(string s) {
        int n= s.length();

        unordered_map<char, int> symbolsValue;
        symbolsValue['I']= 1;
        symbolsValue['V']= 5;
        symbolsValue['X']= 10;
        symbolsValue['L']= 50;
        symbolsValue['C']= 100;
        symbolsValue['D']= 500;
        symbolsValue['M']= 1000;

        if(n == 1)
            return symbolsValue[s[0]];

        int ans= 0;
        for(int i=0; i<n-1; i++) {
            if(symbolsValue[s[i]] >= symbolsValue[s[i+1 && i+1 < n]])
                ans += symbolsValue[s[i]];
            else {
                ans += symbolsValue[s[i+1]] - symbolsValue[s[i && i+1 < n]];
                i++;
            }
        }

        if(symbolsValue[s[n-2]] >= symbolsValue[s[n-1]])
            ans += symbolsValue[s[n-1]];

        return ans;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        int n= s.length();
        int value= 0;

        switch(s[0]) {
            case 'I': {
                value += 1;
                break;
            }
            case 'V': {
                value += 5;
                break;
            }
            case 'X': {
                value += 10;
                break;
            }
            case 'L': {
                value += 50;
                break;
            }
            case 'C': {
                value += 100;
                break;
            }
            case 'D': {
                value += 500;
                break;
            }
            case 'M': {
                value += 1000;
                break;
            }
        }

        for(int i=1; i<n; i++) {
            switch(s[i]) {
                case 'I': {
                    value += 1;
                    break;
                }
                case 'V': {
                    value += 5;
                    if(s[i-1] == 'I')
                        value -= 2;
                    break;
                }
                case 'X': {
                    value += 10;
                    if(s[i-1] == 'I')
                        value -= 2;
                    break;
                }
                case 'L': {
                    value += 50;
                    if(s[i-1] == 'X')
                        value -= 20;
                    break;
                }
                case 'C': {
                    value += 100;
                    if(s[i-1] == 'X')
                        value -= 20;
                    break;
                }
                case 'D': {
                    value += 500;
                    if(s[i-1] == 'C')
                        value -= 200;
                    break;
                }
                case 'M': {
                    value += 1000;
                    if(s[i-1] == 'C')
                        value -= 200;
                    break;
                }
            }
        }
        return value;
    }
};

int main() {
    system("cls");

    string str;
    cout << "Enter Roman Number: ";
    cin >> str;

    Solution s;
    int ans= s.romanToInt(str);

    cout << "Value of Roman Number: " << ans << endl;

    return 0;
}