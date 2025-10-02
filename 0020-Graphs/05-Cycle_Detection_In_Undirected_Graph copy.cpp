#include<bits/stdc++.h>
using namespace std;

// Code 1: BFS
void getAdjacencyList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adj) {
    for(auto edge: edges) {
        int u= edge[0];
        int v= edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
bool bfs(int vertex, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited, unordered_map<int, int>& parent) {
    queue<int> q;
    q.push(vertex);

    isVisited[vertex]= true;
    parent[vertex]= -1;

    while(!q.empty()) {
        int front= q.front();
        q.pop();

        for(auto edge: adj[front]) {
            if(!isVisited[edge]) {
                q.push(edge);
                isVisited[edge]= true;
                parent[edge]= front;
            }
            else if(edge != parent[front] && parent[front] != -1)
                return true;
        }
    }

    return false;
}
string cycleDetection1 (vector<vector<int>>& edges, int n, int m) {
    bool ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;
    unordered_map<int, int> parent;

    getAdjacencyList(edges, adj);

    for(int i=1; i<=n; i++) {
        if(!isVisited[i])
            ans= bfs(i, adj, isVisited, parent);

        if(ans)
            return "Yes";
    }

    return "No";
}

// Code 2: DFS
bool dfs(int vertex, int parentNode, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited) {
    isVisited[vertex]= true;

    for(auto edge: adj[vertex]) {
        if(!isVisited[edge]) {
            bool ans= dfs(edge, vertex, adj, isVisited);

            if(ans)
                return true;
        }
        else if(edge != parentNode)
            return true;
    }

    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    bool ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;

    getAdjacencyList(edges, adj);

    for(int i=1; i<=n; i++) {
        if(!isVisited[i])
            ans= dfs(i, -1, adj, isVisited);

        if(ans)
            return "Yes";
    }

    return "No";
}
