#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int vertex, unordered_map<int, list<int>>& adj, int& timer, vector<int>& disc, vector<int>& low, int parent, vector<bool>& isVisited, vector<vector<int>>& ans) {
    isVisited[vertex]= true;
    disc[vertex]= low[vertex]= timer++;

    for(auto& neighbour: adj[vertex]) {
        if(neighbour == parent)
            continue;
        else if(!isVisited[neighbour]) {
            dfs(neighbour, adj, timer, disc, low, vertex, isVisited, ans);
            
        // BackTrack
            low[vertex]= min(low[vertex], low[neighbour]);

        // Check if Bridge Edge
            if(low[neighbour] > disc[vertex]) {
                vector<int> temp;
                temp.push_back(vertex);
                temp.push_back(neighbour);
                ans.push_back(temp);
            }
        } else {
        // Back Edge
            low[vertex]= min(low[vertex], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for(auto& edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int timer= 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent= -1;
    vector<bool> isVisited(v);
    for(int i=0; i<v; i++) {
        disc[i]= -1;
        low[i]= -1;
        isVisited[i]= false;
    }

    vector<vector<int>> ans;
    for(int i=0; i<v; i++) {
        if(!isVisited[i])
            dfs(i, adj, timer, disc, low, parent, isVisited, ans);
    }

    return ans;
}