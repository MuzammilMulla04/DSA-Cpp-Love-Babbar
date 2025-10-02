#include<bits/stdc++.h>
using namespace std;

// For Topological Sort
void dfs1(int vertex, unordered_map<int, list<int>>& adj, vector<bool>& isVisited, stack<int>& s) {
    isVisited[vertex]= true;

    for(auto& neighbour: adj[vertex]) {
        if(!isVisited[neighbour]) {
            dfs1(neighbour, adj, isVisited, s);
        }
    }

    s.push(vertex);
}
// For Count
void dfs2(int vertex, unordered_map<int, list<int>>& adj, vector<bool>& isVisited) {
    isVisited[vertex]= true;

    for(auto& neighbour: adj[vertex]) {
        if(!isVisited[neighbour]) {
            dfs2(neighbour, adj, isVisited);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	unordered_map<int, list<int>> adj;
    for(auto& edge: edges)
        adj[edge[0]].push_back(edge[1]);

// Get Topological Sort
    stack<int> s;
    vector<bool> isVisited(v, false);

    for(int i=0; i<v; i++) {
        if(!isVisited[i])
            dfs1(i, adj, isVisited, s);
    }

// Graph Transpose
    adj.clear();
    for(auto& edge: edges)
        adj[edge[1]].push_back(edge[0]);
    
// Do DFS
    for(int i=0; i<v; i++)
        isVisited[i]= false;

    int count= 0;
    while(!s.empty()) {
        int top= s.top();
        s.pop();

        if(!isVisited[top]) {
            count++;
            dfs2(top, adj, isVisited);
        }
    }

    return count;
}