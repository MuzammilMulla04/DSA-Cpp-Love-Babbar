#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution {
    bool isInRange(const int& m, const int& n, const int& row, const int& col) {
        return m > row && row >= 0 && n > col && col >= 0;
    }
    bool isCollided(const int& row, const int& col, const vector<vector<int>>& walls) {
        for(const vector<int>& wall: walls) {
            if(row == wall[0] && col == wall[1])
                return true;
        }
        return false;
    }

    void markGuarded(const int& m, const int& n, vector<vector<bool>>& isGuarded, const int& row, const int& col, const vector<vector<int>>& walls) {
        if(!isInRange(m, n, row, col))
            return;
        if(isCollided(row, col, walls)) {
            isGuarded[row][col]= true;
            return;
        }
        if(isGuarded[row][col])
            return;

        isGuarded[row][col]= true;

        markGuarded(m, n, isGuarded, row+1, col, walls);
        markGuarded(m, n, isGuarded, row-1, col, walls);
        markGuarded(m, n, isGuarded, row, col+1, walls);
        markGuarded(m, n, isGuarded, row, col-1, walls);
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> isGuarded(m, vector<bool>(n, false));
        for(const vector<int>& guard: guards)
            markGuarded(m, n, isGuarded, guard[0], guard[1], walls);

        int ans= m*n;
        for(const vector<bool>& row: isGuarded) {
            for(const bool& cell: row) {
                ans -= cell;
            }
        }

        return ans;
    }
};

// 2. Set 
class Solution {
// Custom hash function for unordered_set with pair
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& pair) const {
            return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
        }
    };
// Check if a cell is in range
    bool isInRange(const int& m, const int& n, const int& row, const int& col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
// Mark cells guarded by guards
    void markGuarded(const int& m, const int& n, vector<vector<bool>>& isGuarded, const vector<vector<int>>& guards, unordered_set<pair<int, int>, pair_hash>& wallSet) {
        const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (const vector<int>& guard : guards) {
            wallSet.emplace(guard[0], guard[1]); // Add guards to wallSet
            for (const pair<int, int>& dir : directions) {
                int x = guard[0];
                int y = guard[1];

                while (true) {
                    x += dir.first;
                    y += dir.second;

                // Stop if out of range or blocked
                    if (!isInRange(m, n, x, y) || wallSet.count({x, y})) 
                        break;
                    isGuarded[x][y] = true;
                }
            }
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<pair<int, int>, pair_hash> wallSet;
        for (const vector<int>& wall : walls)
            wallSet.emplace(wall[0], wall[1]);
        
        vector<vector<bool>> isGuarded(m, vector<bool>(n, false));

    // Mark all guarded cells
        markGuarded(m, n, isGuarded, guards, wallSet);

    // Count unguarded cells
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!isGuarded[i][j] && !wallSet.count({i, j})) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// 3. Brute
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 = free, 1 = guard, 2 = wall, 3 = guardable
        
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        auto mark_guarded = [&](int r, int c) {
            for (int row = r + 1; row < m; row++) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int row = r - 1; row >= 0; row--) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int col = c + 1; col < n; col++) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
            for (int col = c - 1; col >= 0; col--) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
        };
        
        for (const auto& guard : guards) {
            mark_guarded(guard[0], guard[1]);
        }
        
        int res = 0;
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 0) res++;
            }
        }
        
        return res;
    }
};