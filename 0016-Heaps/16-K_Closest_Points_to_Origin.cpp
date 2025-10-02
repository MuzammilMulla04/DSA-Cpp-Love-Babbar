#include <bits/stdc++.h>
using namespace std;

class Solution {
    priority_queue<pair<double, int>> maxHeap;

    double distance(int x, int y) {
        return sqrt(x * x + y * y);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        for (int i = 0; i < k; ++i) {
            int x = points[i][0], y = points[i][1];
            double dist = distance(x, y);

            maxHeap.push({dist, i});
        }
        for (int i = k; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            double dist = distance(x, y);

            maxHeap.push({dist, i});
            maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            pair<int, int> top = maxHeap.top();
            maxHeap.pop();

            ans.push_back(points[top.second]);
        }

        return ans;
    }
};