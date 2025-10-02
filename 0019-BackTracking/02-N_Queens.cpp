#include <bits/stdc++.h>
using namespace std;

// Approach 1
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
// Row Check
    for(int i= col; i>=0; i--) {
        if(board[row][i] == 1)
            return false;
    }

// Diagonal Check
    for(int i= row, j= col; i>=0 && j>=0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }
    for(int i= row, j= col; i<n && j>=0; i++, j--) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}
void storeConfigurations(vector<vector<int>>& board, vector<vector<int>>& configurations) {
    vector<int> temp;
    for(vector<int>& row: board) {
        for(int& element: row) {
            temp.push_back(element);
        }
    }
    configurations.push_back(temp);
}
void getConfigurations(vector<vector<int>>& board, int col, int n, vector<vector<int>>& configurations) {
    if(col == n) {
        storeConfigurations(board, configurations);
        return;
    }

    for(int row= 0; row < n; row++) {
        if(isSafe(board, row, col, n)) {
            board[row][col]= 1;

            getConfigurations(board, col+1, n, configurations);

            board[row][col]= 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> configurations;

    getConfigurations(board, 0, n, configurations);
    return configurations;
}

// Approach 2
bool isSafe(vector<vector<int>>& board, int row, int col, int n, unordered_map<int, bool>& rowCheck, unordered_map<int, bool>& upperDiagonalCheck, unordered_map<int, bool>& lowerDiagonalCheck) {
// Row Check
    if(rowCheck[row])
        return false;

// Diagonal Check
    if(upperDiagonalCheck[n-1+row-col])
        return false;
    if(lowerDiagonalCheck[row+col])
        return false;

    return true;
}
void storeConfigurations(vector<vector<int>>& board, vector<vector<int>>& configurations) {
    vector<int> temp;
    for(vector<int>& row: board) {
        for(int& element: row) {
            temp.push_back(element);
        }
    }
    configurations.push_back(temp);
}
void getConfigurations(vector<vector<int>>& board, int col, int n, vector<vector<int>>& configurations, unordered_map<int, bool>& rowCheck, unordered_map<int, bool>& upperDiagonalCheck, unordered_map<int, bool>& lowerDiagonalCheck) {
    if(col == n) {
        storeConfigurations(board, configurations);
        return;
    }

    for(int row= 0; row < n; row++) {
        if(isSafe(board, row, col, n, rowCheck, upperDiagonalCheck, lowerDiagonalCheck)) {
            rowCheck[row]= true;
            upperDiagonalCheck[n-1+row-col]= true;
            lowerDiagonalCheck[row+col]= true;

            board[row][col]= 1;

            getConfigurations(board, col+1, n, configurations, rowCheck, upperDiagonalCheck, lowerDiagonalCheck);

            board[row][col]= 0;

            rowCheck[row]= false;
            upperDiagonalCheck[n-1+row-col]= false;
            lowerDiagonalCheck[row+col]= false;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> configurations;

    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;

    getConfigurations(board, 0, n, configurations, rowCheck, upperDiagonalCheck, lowerDiagonalCheck);
    return configurations;
}
