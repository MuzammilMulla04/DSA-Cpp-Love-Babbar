#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int vertex, vector<bool>& visited, unordered_map<int, list<int>>& adj, int parent, bool& hasCycle) {
    visited[vertex] = true;

    for (auto& neighbour : adj[vertex]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, adj, vertex, hasCycle);
        } else if (neighbour != parent) {
            hasCycle = true;
            return;
        }
    }
}
bool isTree(vector<vector<int>>& edges, int V) {
// Check if E = V-1
    if (edges.size() != V - 1)
        return false;

// Create adjacency list
    unordered_map<int, list<int>> adj;
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

// Cycle detection using DFS
    bool hasCycle = false;
    vector<bool> visited(V, false);

// Start DFS from vertex 0 (assuming the graph is connected)
    dfs(0, visited, adj, -1, hasCycle);

// If cycle is found, it’s not a tree
    if (hasCycle)
        return false;

// Check if all nodes are visited (connected)
    for (bool b : visited) {
        if (!b)
            return false;
    }

// If no cycle and all nodes are visited, it’s a tree
    return true;
}

// Do not change this part of the code. You only need to complete the isTree function above.
int main() {
    system("cls");

    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges(v);

    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    if (isTree(edges, v)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}