#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    int size;
    int offset;
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size, int offset=0): size(size), offset(offset), parent(size+offset), rank(size+offset) {
        for(int i=offset; i<size+offset; i++) {
            parent[i]= i;
            rank[i]= 0;
        }
    }

    int findParent(int node) {
        if(parent[node] == node)
            return node;
        
        parent[node]= findParent(parent[node]);
        return parent[node];
    }
    void unionSet(int node1, int node2) {
        int u= findParent(node1);
        int v= findParent(node2);

        if(rank[u] < rank[v]) {
            parent[u]= v;
        } else {
            parent[v]= u;

            if(rank[u] == rank[v])
                rank[u]++;
        }
    }
    bool checkSameComponents(int node1, int node2) {
        int p1= findParent(node1);
        int p2= findParent(node2);
        return p1 == p2;
    }

    void print() {
        cout << endl << "Node:\t";
        for(int i=offset; i<size+offset; i++)
            cout << i << " ";

        cout << endl << "Parent:\t";
        for(int i=offset; i<size+offset; i++)
            cout << parent[i] << " ";

        cout << endl << "Rank:\t";
        for(int i=offset; i<size+offset; i++)
            cout << rank[i] << " ";
        cout << endl;
    }
};
bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), compare);
    DisjointSet s(n);

    int weightMST= 0;
    for(auto& edge: edges) {
        int u= edge[0];
        int v= edge[1];
        int w= edge[2];

        if(!s.checkSameComponents(u, v)) {
            s.unionSet(u, v);
            weightMST += w;
        }
    }

    return weightMST;
}