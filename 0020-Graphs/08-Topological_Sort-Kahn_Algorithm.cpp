#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
// Get adj & Indegree
    unordered_map<int, list<int>> adj;
    vector<int> indegree(v, 0);
    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

// Fill queue for 1st loop of all components
    queue<int> q;
    for(int i=0; i<indegree.size(); i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

// do bfs
    vector<int> ans;
    while(!q.empty()) {
        int front= q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front]) {
            indegree[neighbour]--;

            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}
