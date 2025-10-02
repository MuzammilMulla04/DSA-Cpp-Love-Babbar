#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& sudoku, int n, int row, int col, int num) {
    for(int i=0; i<n; i++) {
    // Row Check
        if(sudoku[row][i] == num)
            return false;
    // Col Check
        if(sudoku[i][col == num])
            return false;
    // 3x3 Check
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == num)
            return false;
    }

    return true;
}
bool solve(vector<vector<int>>& sudoku) {
    int n= sudoku.size();

    for(int row=0; row<n; row++) {
        for(int col= 0; col<n; col++) {
            // Empty Space
            if(sudoku[row][col] == 0) {
                for(int num=1; num<=n; num++) {
                    if(isSafe(sudoku, n, row, col, num)) {
                        sudoku[row][col]= num;
                    
                        if(solve(sudoku))       // Recursive Call
                            return true;
                        else
                            sudoku[row][col]= 0;    // Backtrack
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
	solve(sudoku);
}