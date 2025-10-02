#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> nums;
        for (const string& str : arr) {
            if (isdigit(str[0]) || str.size() > 1) {
                nums.push(stoi(str));
                continue;
            }

            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            int res = 0;
            if (str == "+") {
                res = num1 + num2;
            } else if (str == "-") {
                res = num1 - num2;
            } else if (str == "*") {
                res = num1 * num2;
            } else {
                res = num1 / num2;
            }

            nums.push(res);
        }

        return nums.top();
    }
};