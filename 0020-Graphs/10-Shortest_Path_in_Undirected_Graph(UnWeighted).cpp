#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int noOfVertices, int noOfEdges, int source, int target) {
// Get adj
    vector<vector<int>> adj(noOfVertices+1, vector<int>());
    for(auto edge: edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

// Do bfs, to make parent[]
    vector<bool> visited(noOfVertices+1, false);
    vector<int> parent(noOfVertices+1);
    queue<int> q;

    q.push(source);
    visited[source]= true;
    parent[source]= -1;

    while(!q.empty()) {
        int front= q.front();
        q.pop();

        for(auto neighbour: adj[front]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour]= true;
                parent[neighbour]= front;
            }
        }
    }

// Backtrack
    vector<int> ans;
    ans.push_back(target);
    
    for(int temp= target; temp != source; temp= parent[temp])
        ans.push_back(temp);

// Path is reversed, So Reverse it again!
    for(int i=0, j= ans.size()-1; i<j; i++, j--)
        swap(ans[i], ans[j]);
    
    return ans;
}
