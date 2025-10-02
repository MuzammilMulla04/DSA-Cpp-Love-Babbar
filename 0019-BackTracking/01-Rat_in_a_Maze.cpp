#include <bits/stdc++.h>
using namespace std;

bool isInRange(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}
bool isVisited(vector<vector<int>>& arr, int x, int y) {
    return arr[x][y] == 0;
}
bool isEnd(vector<vector<int>>& arr, int x, int y, int n) {
    return x == n-1 && y == n-1;
}

void solve(vector<vector<int>>& arr, int n, int x, int y, string path, vector<string>& paths) {
    if(!isInRange(x, y, n))
        return;
    if(isVisited(arr, x, y))
        return;
    
    if(isEnd(arr, x, y, n)) {
        paths.push_back(path);
        return;
    }
// Mark Visited
    arr[x][y]= 0;

// Go Down
    solve(arr, n, x+1, y, path + 'D', paths);
// Go Left
    solve(arr, n, x, y-1, path + 'L', paths);
// Go Right
    solve(arr, n, x, y+1, path + 'R', paths);
// Go Up
    solve(arr, n, x-1, y, path + 'U', paths);

// Mark Un-Visited
    arr[x][y]= 1;
}
vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> paths;
    solve(arr, n, 0, 0, "", paths);
    return paths;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    cout << "Enter Matrix:-" << endl;
    for(vector<int>& row: arr) {
        for(int& element: row) {
            cin >> element;
        }
    }

    vector<string> paths= searchMaze(arr, n);

    cout << "Subsets:-" << endl;
    for(string str: paths) {
        cout << str << endl;
    }

    return 0;
}