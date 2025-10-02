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
        return parent[node1] == parent[node2];
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

int main() {
    system("cls");

    DisjointSet s(7, 1);

    s.unionSet(1, 2);
    s.unionSet(2, 3);
    s.unionSet(4, 5);
    s.unionSet(6, 7);
    s.unionSet(5, 6);
    s.unionSet(3, 7);

    s.print();

    return 0;
}