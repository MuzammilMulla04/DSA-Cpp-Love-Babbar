#include <bits/stdc++.h>
using namespace std;

// Iterative
bool dfs(int vertex, unordered_map<int, list<int>>& adj, vector<bool>& isVisited, vector<bool>& dfsVisited) {
    stack<int> s;
    s.push(vertex);
    isVisited[vertex]= true;
    dfsVisited[vertex]= true;

    while(!s.empty()) {
        int top= s.top();

        bool adjPresent= false;
        for(auto edge: adj[top]) {
            if(!isVisited[edge]) {
                s.push(edge);
                isVisited[edge]= true;
                dfsVisited[edge]= true;

                adjPresent= true;
                break;
            } else if(dfsVisited[edge]) {
                return 1;
            }
        }

        if(!adjPresent) {
            dfsVisited[top]= false;
            s.pop();
        }
    }

    return 0;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    vector<bool> isVisited(n+1, false);
    vector<bool> dfsVisited(n+1, false);

    for(auto edge: edges) 
        adj[edge.first].push_back(edge.second);
    
    for(int i=1; i<=n; i++) {
        if(!isVisited[i]) {
            bool ans= dfs(i, adj, isVisited, dfsVisited);

            if(ans)
                return 1;
        }
    }

    return 0;
}

// Recursive
bool dfs(int vertex, unordered_map<int, list<int>>& adj, vector<bool>& isVisited, vector<bool>& dfsVisited) {
    isVisited[vertex]= true;
    dfsVisited[vertex]= true;

    for(auto edge: adj[vertex]) {
        if(!isVisited[edge]) {
            bool ans= dfs(edge, adj, isVisited, dfsVisited);

            if(ans)
                return 1;
        } else if(dfsVisited[edge]) {
            return 1;
        }
    }

    dfsVisited[vertex]= false;
    return 0;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    vector<bool> isVisited(n+1, false);
    vector<bool> dfsVisited(n+1, false);

    for(auto edge: edges) 
        adj[edge.first].push_back(edge.second);
    
    for(int i=1; i<=n; i++) {
        if(!isVisited[i]) {
            bool ans= dfs(i, adj, isVisited, dfsVisited);

            if(ans)
                return 1;
        }
    }

    return 0;
}
