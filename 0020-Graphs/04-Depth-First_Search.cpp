#include<bits/stdc++.h>
using namespace std;

void getAjacencyList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adj) {
    for(auto edge: edges) {
        int u= edge[0];
        int v= edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

/* Recursive
void dfs(unordered_map<int, list<int>>& adj, vector<bool>& isVisited, vector<int>& component, int vertex) {
    component.push_back(vertex);
    isVisited[vertex]= true;

    for(auto node: adj[vertex]) {
        if(!isVisited[node])
            dfs(adj, isVisited, component, node);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<bool> isVisited(V, false);
    unordered_map<int, list<int>> adj;

    getAjacencyList(edges, adj);

    for(int i=0; i<V; i++) {
        if(!isVisited[i]) {
            vector<int> component;
            dfs(adj, isVisited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}
 */
/* Iterative
void dfsIterative(int vertex, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited, vector<int>& temp) {
    stack<int> s;
    s.push(vertex);
    isVisited[vertex]= true;

    while(!s.empty()) {
        int top= s.top();
        s.pop();

        temp.push_back(top);

        for(auto edge: adj[top]) {
            if(!isVisited[edge]) {
                s.push(edge);
                isVisited[edge]= true;
            }
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;
    vector<vector<int>> ans;
    getAjacencyList(edges, adj);

    for(int i=0; i<V; i++) {
        if(!isVisited[i]) {
            vector<int> temp;
            dfsIterative(i, adj, isVisited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}
 */

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
    void dfs(T vertex, vector<T>& temp, unordered_map<T, bool>& isVisited) {
        temp.push_back(vertex);
        isVisited[vertex]= true;

        for(T edge: adjacencyList[vertex]) {
            if(!isVisited[edge])
                dfs(edge, temp, isVisited);
        }
    }
    void dfsIterative(int vertex, vector<T>& temp, unordered_map<T, bool>& isVisited) {
        stack<int> s;
        s.push(vertex);
        isVisited[vertex]= true;

        while(!s.empty()) {
            int top= s.top();
            s.pop();

            temp.push_back(top);

            for(auto edge: adjacencyList[top]) {
                if(!isVisited[edge]) {
                    s.push(edge);
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
    void printDFS(T source) {
        vector<T> ans= dfstraversal(source);
        cout << "DFS Traversal: ";
        for(auto i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    void printDFSComponents() {
        vector<vector<T>> ans= dfsComponents();
        for(auto& component: ans) {
            for(auto& vertex: component) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
// Traversals
    //BFS
    vector<T> bfsTraversal(T source) {
        vector<T> ans;
        unordered_map<T, bool> isVisited;

        bfs(source, ans, isVisited);
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
    //DFS: Recursive
    vector<T> dfstraversal(T source) {
        vector<T> ans;
        unordered_map<T, bool> isVisited;

        dfs(source, ans, isVisited);
        return ans;
    }
    vector<vector<T>> dfsComponents() {
        vector<vector<T>> ans;
        unordered_map<T, bool> isVisited;

        for(int i=0; i<noOfVertices; i++) {
            if(!isVisited[i]) {
                vector<T> temp;
                dfs(i, temp, isVisited);
                ans.push_back(temp);
            }
        }

        return ans;
    }
    //DFS: Iterative
    vector<T> dfstraversalIterative(T source) {
        vector<T> ans;
        unordered_map<T, bool> isVisited;

        dfsIterative(source, ans, isVisited);
        return ans;
    }
    vector<vector<T>> dfsComponentsTerative() {
        vector<vector<T>> ans;
        unordered_map<T, bool> isVisited;

        for(int i=0; i<noOfVertices; i++) {
            if(!isVisited[i]) {
                vector<T> temp;
                dfsIterative(i, temp, isVisited);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main() {
    system("cls");

    Graph<int> g(9, 8, false);
    g.printDFSComponents();

    vector<vector<int>> ans= g.dfsComponentsTerative();
    for(auto& component: ans) {
        for(auto& vertex: component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
