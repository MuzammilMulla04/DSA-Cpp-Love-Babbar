#include <bits/stdc++.h>
using namespace std;

// My Approach
class Solution {
    void getMapping(unordered_map<int, string>& roman) {
        roman[1000]= "M";

        roman[900]= "CM";
        roman[500]= "D";
        roman[400]= "CD";
        roman[100]= "C";

        roman[90]= "XC";
        roman[50]= "L";
        roman[40]= "XL";
        roman[10]= "X";

        roman[9]= "IX";
        roman[5]= "V";
        roman[4]= "IV";
        roman[1]= "I";
    }
public:
    string intToRoman(int num) {
        unordered_map<int, string> roman;
        getMapping(roman);

        string ans= "";
        int factor= 1000;
        while(num > 0) {
            int b= num-num%factor;

            if(roman.count(b) == 1) {
                ans += roman[b];
            } else {
                int cond= b/factor;
                if(cond >= 5) {
                    int temp= 5*factor;
                    ans += roman[temp];
                    cond -= 5;
                }

                while(cond > 0) {
                    ans += roman[factor];
                    cond--;
                }
            }

            factor /= 10;
            num -= b;
        }
        

        return ans;
    }
};

// Yui's Approach
class Solution {
public:
    string intToRoman(int num) {
        // Pre-defined mappings of values to Roman numerals
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string ans = "";

        // Iterate over the mappings, subtracting from num and building the result
        for (auto& [value, symbol] : roman) {
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }

        return ans;
    }
};

//Stupid People on Leetcode
class Solution {
public:
    string intToRoman(int num) {
        // Arrays to store the Roman numeral representations for each place value
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[] = {"","M","MM","MMM"};
        
        // Construct the Roman numeral by indexing into the arrays
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};
