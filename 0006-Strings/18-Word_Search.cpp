#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool inRange(int i, int j, int m, int n) {
        return i>=0 && j>=0 && i<m && j<n;
    }

    void solve(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int m, int n, string word, int index, bool& isFound) {
        if(!inRange(i, j, m, n))
            return;
        if(visited[i][j])
            return;
        
        if(board[i][j] != word[index])
            return;

        if(index+1 == word.size() && board[i][j] == word[index]) {
            isFound= true;
            return;
        }


        visited[i][j]= true;
        index++;

        if(!isFound)
            solve(board, visited, i+1, j, m, n, word, index, isFound);
        if(!isFound)
            solve(board, visited, i, j+1, m, n, word, index, isFound);

        if(!isFound)
            solve(board, visited, i-1, j, m, n, word, index, isFound);
        if(!isFound)
            solve(board, visited, i, j-1, m, n, word, index, isFound);
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n= board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        bool isFound= false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j])
                    solve(board, visited, i, j, m, n, word, 0, isFound);

                if(isFound)
                    return isFound;
            }
        }
                
        return isFound;
    }
};
