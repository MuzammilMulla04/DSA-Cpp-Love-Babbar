#include<bits/stdc++.h>
using namespace std;

// Code 1: adj given
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    vector<bool> isVisited(n, false);

    queue<int> q;
    q.push(0);
    isVisited[0]= true;

    while(!q.empty()) {
        int front= q.front();
        q.pop();

        ans.push_back(front);

        for(auto vertex: adj[front]) {
            if(!isVisited[vertex]) {
                q.push(vertex);
                isVisited[vertex]= true;
            }
        }
    }

    return ans;
}

// Code 2: adj not given
// Use set if nodes asked in order...
void getAdjacencyList(vector<pair<int, int>> &edges, unordered_map<int, list<int>>& adj) {
    for(auto edge: edges) {
        int u= edge.first;
        int v= edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited, vector<int>& ans, int vertex) {
    queue<int> q;
    q.push(vertex);
    isVisited[vertex]= true;

    while(!q.empty()) {
        int front= q.front();
        q.pop();

        ans.push_back(front);

        for(auto node: adj[front]) {
            if(!isVisited[node]) {
                isVisited[node]= true;
                q.push(node);
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<pair<int, int>> &edges) {
    vector<int> ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;

    getAdjacencyList(edges, adj);

    for(int i=0; i<n; i++) {
        if(!isVisited[i])
            bfs(adj, isVisited, ans, i);
    }

    return ans;
}

// Code 3: in class 'Graph'
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
    void bfs(T vertex, vector<T>& temp, unordered_map<T, bool>& isVisited) {
        queue<T> q;
        q.push(vertex);
        isVisited[vertex]= true;

        while(!q.empty()) {
            T front= q.front();
            q.pop();

            temp.push_back(front);

            for(T edge: adjacencyList[front]) {
                if(!isVisited[edge]) {
                    q.push(edge);
                    isVisited[edge]= true;
                }
            }
        }
    }
public:
// Constructor
    Graph(): noOfVertices(0), noOfEdges(0), isDirected(false) {}
    Graph(int v, bool d): noOfVertices(v), noOfEdges(0), isDirected(d) {
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
    Graph(int v, int e, bool d): noOfVertices(v), noOfEdges(0), isDirected(d) {
        for(int i=0; i<e; i++) {
            T source, destination;
            cout << "Enter Source & Destination: ";
            cin >> source >> destination;

            addEdge(source, destination);
        }
    }
// Printers
    void printAdjacencyList() {
        for(auto vertex: adjacencyList) {
            cout << vertex.first << "-> ";

            for(auto edge: vertex.second) {
                cout << edge << ", ";
            }
            cout << endl;
        }
    }
    void printBFS(T source) {
        vector<T> ans= bfsTraversal(source);
        for(T vertex: ans) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    void printBFSComponents() {
        vector<vector<T>> ans= bfsComponents();
        for(auto& component: ans) {
            for(auto& vertex: component) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
// Traversals
    vector<T> bfsTraversal(T source) {
        vector<T> ans;
        unordered_map<T, bool> isVisited;

        queue<T> q;
        q.push(source);
        isVisited[source]= true;

        while(!q.empty()) {
            T front= q.front();
            q.pop();

            ans.push_back(front);

            for(T edge: adjacencyList[front]) {
                if(!isVisited[edge]) {
                    q.push(edge);
                    isVisited[edge]= true;
                }
            }
        }

        return ans;
    }
    vector<vector<T>> bfsComponents() {
        vector<vector<T>> ans;
        unordered_map<T, bool> isVisited;

        for(int i=0; i<noOfVertices; i++) {
            if(!isVisited[i]) {
                vector<T> temp;
                bfs(i, temp, isVisited);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main() {
    system("cls");

    Graph<int> g(7, 7, false);
    g.printBFSComponents();

    return 0;
}