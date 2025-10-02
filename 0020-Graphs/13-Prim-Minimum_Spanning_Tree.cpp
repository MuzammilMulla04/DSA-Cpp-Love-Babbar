#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
// Create adj
    unordered_map<int, list<pair<int, int>>> adj;
    for(auto& trio: g) {
        int u= trio.first.first;
        int v= trio.first.second;
        int w= trio.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
// Initialize DS
    vector<int> key(n+1);
    vector<int> mst(n+1);
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++) {
        key[i]= INT_MAX;
        mst[i]= false;
        parent[i]= -1;
    }

    key[1]= 0;
    parent[1]= -1;

    for(int i=1; i<n; i++) {
        int mini= INT_MAX;
        int u;

        // Find u [minimum dist]
        for(int v=1; v<=n; v++) {
            if(!mst[v] && key[v] < mini) {
                u= v;
                mini= key[v];
            }
        }

        // Set mst[u]
        mst[u]= true;

        // check adj nodes
        for(auto edge: adj[u]) {
            int v= edge.first;
            int w= edge.second;

            if(!mst[v] && w<key[v]) {
                key[v]= w;
                parent[v]= u;
            }
        }

        
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++)
        ans.push_back({{parent[i], i}, key[i]});

    return ans;
}

class compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
// Create adj
    unordered_map<int, list<pair<int, int>>> adj;
    for(auto& trio: g) {
        int u= trio.first.first;
        int v= trio.first.second;
        int w= trio.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
// Initialize DS
    vector<int> key(n+1);
    vector<int> mst(n+1);
    vector<int> parent(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
    key[1]= 0;
    parent[1]= -1;

    for(int i=2; i<=n; i++) {
        key[i]= INT_MAX;
        mst[i]= false;
        parent[i]= -1;
        minHeap.push({i, key[i]});
    }


    for(int i=1; i<n; i++) {
        // Find u [minimum dist]
        pair<int, int> top= minHeap.top();
        minHeap.pop();
        int u= top.first;
        int mini= top.second;

        // Set mst[u]
        mst[u]= true;

        // check adj nodes
        for(auto edge: adj[u]) {
            int v= edge.first;
            int w= edge.second;

            if(!mst[v] && w<key[v]) {
                key[v]= w;
                parent[v]= u;

                minHeap.push({v, key[v]});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++)
        ans.push_back({{parent[i], i}, key[i]});

    return ans;
}
