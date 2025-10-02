#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Get adj & Indegree
    unordered_map<int, list<int>> adj;
    vector<int> indegree(n+1, 0);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        indegree[edge.second]++;
    }

    // Fill queue for 1st loop of all components
    queue<int> q;
    for (int i = 1; i <= indegree.size(); i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int count= 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return count != n;
}