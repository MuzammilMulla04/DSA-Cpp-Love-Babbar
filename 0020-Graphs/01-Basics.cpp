#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    int noOfVertices, noOfEdges;
    unordered_map<T, list<T>> adjacencyList;
public:
// Constructor
    Graph(): noOfVertices(0), noOfEdges(0) {}
    Graph(int noOfVertices, int noOfEdges): noOfVertices(noOfVertices), noOfEdges(0) {
        for(int i=0; i<noOfEdges; i++) {
            T source, destination;
            cout << "Enter Source: ";
            cin >> source;

            cout << "Enter Destination: ";
            cin >> destination;

            addEdge(source, destination, 0);
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
            cout << vertex.first << "-> ";

            for(auto edge: vertex.second) {
                cout << edge << ", ";
            }
            cout << endl;
        }
    }
};

int main () {
    system("cls");

    int noOfVertices, noOfEdges;
    cout << "Enter no. of Vertices: ";
    cin >> noOfVertices;

    cout << "Enter no. of Edges: ";
    cin >> noOfEdges;

    Graph<int> g(noOfVertices, noOfEdges);
    g.printAdjacencyList();

    cout << endl;
    return 0;
}