#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> iterators;
    stack<char> encoded;

    void expand(const string& repeat, const int& iter) {
        for (int i = 0; i < iter; ++i) {
            for (int j = 0; j < repeat.size(); ++j) {
                encoded.push(repeat[j]);
            }
        }
    }
    void decode() {
        string repeat = "";
        while (encoded.top() != '[') {
            repeat += encoded.top();
            encoded.pop();
        }
        encoded.pop();
        for (int i = 0, j = repeat.size() - 1; i < j; ++i, --j)
            swap(repeat[i], repeat[j]);

        int iter = iterators.top();
        iterators.pop();
        expand(repeat, iter);
    }

public:
    string decodedString(string& str) {
        int num = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (isdigit(str[i])) {
                num *= 10;
                num += str[i] - '0';
            } else if (str[i] == '[') {
                iterators.push(num);
                num = 0;

                encoded.push('[');
            } else if (str[i] == ']') {
                decode();
            } else {
                encoded.push(str[i]);
            }
        }

        string ans = "";
        while (!encoded.empty()) {
            ans += encoded.top();
            encoded.pop();
        }
        for (int i = 0, j = ans.size() - 1; i < j; ++i, --j) {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};
