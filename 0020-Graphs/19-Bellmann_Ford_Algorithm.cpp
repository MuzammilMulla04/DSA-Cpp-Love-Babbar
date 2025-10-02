#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, INT_MAX);
    dist[src]= 0;

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int u= edges[j][0];
            int v= edges[j][1];
            int w= edges[j][2];

            if(dist[u] != INT_MAX && (dist[u] + w < dist[v])) {
                dist[v]= dist[u] + w;
            }
        }
    }

    bool flag= false;    
    for(int j=0; j<m; j++) {
        int u= edges[j][0];
        int v= edges[j][1];
        int w= edges[j][2];

        if(dist[u] != INT_MAX && (dist[u] + w < dist[v])) {
            flag= true;
            break;
        }
    }

    if(flag)
        return vector<int>(n, -1);
    else
        return dist;
}