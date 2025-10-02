#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, unordered_map<int, list<int>>& adj, vector<int>& visited, stack<int>& s) {
    visited[vertex]= true;

    for(auto neighbour: adj[vertex]) {
        if(!visited[neighbour])
            dfs(neighbour, adj, visited, s);
    }

    s.push(vertex);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for(auto edge: edges)
        adj[edge[0]].push_back(edge[1]);

    vector<int> visited(v, false);
    stack<int> s;
    for(int i=0; i<v; i++) {
        if(!visited[i])
            dfs(i, adj, visited, s);
    }

    vector<int> ans;
    while(!s.empty()) {
        int top= s.top();
        s.pop();

        ans.push_back(top);
    }

    return ans;
}
