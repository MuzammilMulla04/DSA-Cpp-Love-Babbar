#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    int noOfVertices, noOfEdges;
    map<T, list<pair<T, T>>> adjacencyList;
    bool isDirected;

    const int Infinity= INT_MAX;
// Helpers
    void addEdge(T u, T v, T w) {
        adjacencyList[u].push_back(make_pair(v, w));
    }
    void topologicalTraveral(T vertex, unordered_map<T, bool>& visited, stack<T>& s) {
        visited[vertex]= true;

        for(auto edge: adjacencyList[vertex]) {
            if(!visited[edge.first])
                topologicalTraveral(edge.first, visited, s);
        }

        s.push(vertex);
    }
public:
    Graph(int v, int e, bool b): noOfVertices(v), noOfEdges(e), isDirected(b) {
        for(int i=0; i<noOfEdges; i++) {
            if(isDirected) {
                T u, v, w;
                cout << "Enter S, D & W: ";
                // cout << "Enter Source, Destination & Weight: ";
                cin >> u >> v >> w;

                addEdge(u, v, w);
            } else {
                T u, v, w, rw;
                cout << "Enter S, D & W, RW: ";
                // cout << "Enter Source, Destination & Weight, Reverse-Weight: ";
                cin >> u >> v >> w >> rw;

                addEdge(u, v, w);
                addEdge(v, u, rw);
            }
        }
    }
    void printAdjacencyList() {
        for(auto vertex: adjacencyList) {
            cout << vertex.first << ": ";

            for(auto edge: vertex.second) {
                cout << "[" << edge.first << ", " << edge.second << "], ";
            }

            cout << endl;
        }
    }
    stack<T> getTopologicalSort() {
        stack<T> s;
        unordered_map<T, bool> visited;
        for(auto map: adjacencyList) {
            if(!visited[map.first])
                topologicalTraveral(map.first, visited, s);
        }

        return s;
    }

    vector<T> getShortestPath(T source) {
        stack<T> s= getTopologicalSort();

        vector<T> dist(noOfVertices, Infinity);
        dist[source]= 0;

        while(!s.empty()) {
            T top= s.top();
            s.pop();

            if(dist[top] != Infinity) {
                for(auto edge: adjacencyList[top]) {
                    if(dist[top] + edge.second < dist[edge.first])
                        dist[edge.first]= dist[top] + edge.second;
                }
            }
        }
        
        return dist;
    }
};

int main() {
    system("cls");

    Graph<int> g(6, 9, 1);
/* Edge List
    0 1 5
    0 2 3
    1 2 2
    1 3 6
    2 3 7
    2 4 4
    3 4 -1
    4 5 -2
    2 5 2
*/

    vector<int> ans= g.getShortestPath(1);

    cout << endl << "Dist: ";
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}