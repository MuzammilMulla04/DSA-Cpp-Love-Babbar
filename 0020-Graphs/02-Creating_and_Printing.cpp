#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    int noOfVertices, noOfEdges;
    vector<vector<T>> adjacencyList;
public:
// Constructor
    Graph(int noOfVertices, int noOfEdges, vector<vector<T>>& edges): noOfVertices(noOfVertices), noOfEdges(0), adjacencyList(noOfVertices) {
        for(auto edge: edges) {
            addEdge(edge[0], edge[1], false);
        }
    }
// Functions
    void addEdge(T u, T v, bool isDirected) {
        adjacencyList[u].push_back(v);
        if(!isDirected)
            adjacencyList[v].push_back(u);

        noOfEdges++;
    }
    void printAdjacencyList() {
        for(auto vertex: adjacencyList) {
            cout << vertex << "-> ";

            for(auto edge: vertex) {
                cout << edge << ", ";
            }
            cout << endl;
        }
    }
    vector<vector<T>> getAdjacency() {
        vector<vector<T>> ans;
        for(int i=0; i<adjacencyList.size(); i++) {
            vector<T> temp;
            temp.push_back(i);
            for(auto& edge: adjacencyList[i]) {
                temp.push_back(edge);
            }
            ans.push_back(temp);
        }
        return ans;
    }};

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    Graph<int> g(n, m, edges);
    return g.getAdjacency();
}