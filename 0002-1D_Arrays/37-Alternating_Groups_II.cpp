#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int m = colors.size(), n = m + k - 1;
        int ans = 0;

        int alternating = 1;
        int prevColor = colors[0];
        for (int i = 1; i < n; ++i) {
            int index = i % m;

            if (colors[index] == prevColor) {
                alternating = 1;
            } else {
                ++alternating;

                if (alternating >= k)
                    ++ans;
            }

            prevColor = colors[index];
        }

        return ans;
    }
};