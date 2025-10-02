#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> tree;
    vector<int> distanceFromBob;

    int dfs(int node, int parent, int time, int bob, vector<int>& amount) {
        int maxChildProfit = INT_MIN;

        // Calculate the node's distance from Bob
        if (node == bob)
            distanceFromBob[node] = 0;

        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue;

            maxChildProfit = max(maxChildProfit, dfs(neighbor, node, time + 1, bob, amount));
            distanceFromBob[node] = min(distanceFromBob[node], distanceFromBob[neighbor] + 1);
        }

        int nodeProfit = 0;
        if (distanceFromBob[node] > time)
            nodeProfit = amount[node];  // Alice reaches first
        else if (distanceFromBob[node] == time)
            nodeProfit = amount[node] / 2;  // Alice and Bob reach at the same time

        return (maxChildProfit == INT_MIN) ? nodeProfit : nodeProfit + maxChildProfit;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        distanceFromBob.resize(n, n);  // Initialize with maximum possible distance

        // Build the tree from edges
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, 0, bob, amount);
    }
};
