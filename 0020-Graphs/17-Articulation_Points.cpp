#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    int noOfVertices, noOfEdges;
    unordered_map<T, list<T>> adjacencyList;
    bool isDirected;

// Helpers
    void addEdge(T u, T v) {
        adjacencyList[u].push_back(v);
        if(!isDirected)
            adjacencyList[v].push_back(u);

        noOfEdges++;
    }
public:
// Constructor
    Graph(int noOfVertices, bool isDirected): noOfVertices(noOfVertices), noOfEdges(0), isDirected(isDirected) {
        int option= 1;
        while(option != -1) {
            T source, destination;
            cout << "Enter Source: ";
            cin >> source;

            cout << "Enter Destination: ";
            cin >> destination;

            addEdge(source, destination);

            cout << "Press (-1) to stop: ";
            cin >> option;
        }
    }
// Getters
    int getNoOfVertices() {
        return noOfVertices;
    }
    int getNoOfEdges() {
        return noOfEdges;
    }
    unordered_map<T, list<T>> getAdjacencyList() {
        return adjacencyList;
    }
};

void dfs(int vertex, unordered_map<int, list<int>>& adjacencyList, vector<int>& disc, vector<int>& low, int parent, vector<bool>& isVisited, int& timer, vector<int>& ans) {
    isVisited[vertex]= true;
    disc[vertex]= low[vertex]= timer++;

    int child= 0;
    for(auto& neighbour: adjacencyList[vertex]) {
        if(neighbour == parent)
            continue;
        else if(!isVisited[neighbour]) {
            dfs(neighbour, adjacencyList, disc, low, vertex, isVisited, timer, ans);
            low[vertex]= min(low[vertex], low[neighbour]);

            if(low[neighbour] >= disc[vertex] && parent != -1) {
                ans[vertex]= true;
            }
            child++;
        } else {
            low[vertex]= min(low[vertex], disc[neighbour]);
        }
    }

    if(parent == -1 && child > 1)
        ans[vertex]= true;
}
vector<int> tarjanAlgorithm(Graph<int>& g) {
    int v= g.getNoOfVertices();
    unordered_map<int, list<int>> adjacencyList= g.getAdjacencyList();

    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> isVisited(v);

    for(int i=0; i<v; i++) {
        disc[i]= -1;
        low[i]= -1;
        isVisited[i]= false;
    }

    vector<int> ans(v, false);
    int timer= 0;
    for(int i=0; i<v; i++) {
        if(!isVisited[i])
            dfs(i, adjacencyList, disc, low, -1, isVisited, timer, ans);
    }

    return ans;
}

int main() {
    system("cls");

    Graph<int> g(5, false);
    vector<int> articulationPoints= tarjanAlgorithm(g);

    cout << "Articulation Points: ";
    for(int i=0; i<articulationPoints.size(); i++) {
        if(articulationPoints[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}