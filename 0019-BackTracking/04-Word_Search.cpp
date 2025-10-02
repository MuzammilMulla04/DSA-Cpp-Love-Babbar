#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;

// Helper function to check if a given position is within the grid boundaries
    bool isInRange(int i, int j) const {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

// Recursive function to check if the word can be found starting from the given position
    bool solve(vector<vector<char>>& board, string& word, vector<vector<bool>>& isVisited, int i, int j, int index = 1) {
    // If we've matched the entire word, return true
        if (word.size() == index)
            return true;

    // Mark the current cell as visited
        isVisited[i][j] = true;
        bool ans = false;

    // Check the cell below
        if (isInRange(i + 1, j) && !isVisited[i + 1][j] && !ans && board[i + 1][j] == word[index])
            ans = solve(board, word, isVisited, i + 1, j, index + 1);
    // Check the cell above
        if (isInRange(i - 1, j) && !isVisited[i - 1][j] && !ans && board[i - 1][j] == word[index])
            ans = solve(board, word, isVisited, i - 1, j, index + 1);
    // Check the cell to the right
        if (isInRange(i, j + 1) && !isVisited[i][j + 1] && !ans && board[i][j + 1] == word[index])
            ans = solve(board, word, isVisited, i, j + 1, index + 1);
    // Check the cell to the left
        if (isInRange(i, j - 1) && !isVisited[i][j - 1] && !ans && board[i][j - 1] == word[index])
            ans = solve(board, word, isVisited, i, j - 1, index + 1);

    // Unmark the current cell (backtrack)
        isVisited[i][j] = false;
        return ans;
    }

public:
// Main function to determine if the word exists in the grid
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

    // Create a 2D vector to track visited cells
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        bool ans = false;

    // Iterate over each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            // If the current cell matches the first character of the word, start the search
                if (board[i][j] == word[0])
                    ans = solve(board, word, isVisited, i, j);

            // If the word is found, return true
                if (ans)
                    return true;
            }
        }

    // If the word is not found, return false
        return false;
    }
};
