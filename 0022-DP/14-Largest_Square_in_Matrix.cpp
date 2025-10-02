#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution {
	int solve(vector<vector<int>>& matrix, int i, int j, int& maxSize) {
		if(i >= matrix.size() || j >= matrix[0].size()) {
			return 0;
		}

		int right= solve(matrix, i, j+1, maxSize);
		int diagonal= solve(matrix, i+1, j+1, maxSize);
		int down= solve(matrix, i+1, j, maxSize);

		if(matrix[i][j] == 1) {
			int ans= 1 + min(right, min(diagonal, down));
			maxSize= max(maxSize, ans);
			return ans;
		} else {
			return 0;
		}
	}
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
		int maxSize= 0;
		solve(mat, 0, 0, maxSize);
		return maxSize;
    }
};

// 2. Recursion + Memoization
class Solution {
	int solve(vector<vector<int>>& matrix, int i, int j, int& maxSize, vector<vector<int>>& dp) {
		if(i >= matrix.size() || j >= matrix[0].size()) {
			return 0;
		}
		if(dp[i][j] != -1)
			return dp[i][j];

		int right= solve(matrix, i, j+1, maxSize, dp);
		int diagonal= solve(matrix, i+1, j+1, maxSize, dp);
		int down= solve(matrix, i+1, j, maxSize, dp);

		if(matrix[i][j] == 1) {
			dp[i][j]= 1 + min(right, min(diagonal, down));
			maxSize= max(maxSize, dp[i][j]);
			return dp[i][j];
		} else {
			return dp[i][j]= 0;
		}
	}
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
		int maxSize= 0;
		vector<vector<int>> dp(n, vector<int>(m, -1));

		solve(mat, 0, 0, maxSize, dp);
		return maxSize;
    }
};

// 3. Tabulation SC: O(m*n)
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix) {
		int maxSize= 0;
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

		for(int i=n-1; i>=0; i--) {
			for(int j=m-1; j>=0; j--) {
				int right= dp[i][j+1];
				int diagonal= dp[i+1][j+1];
				int down= dp[i+1][j];

				if(matrix[i][j] == 1) {
					dp[i][j]= 1 + min(right, min(diagonal, down));
					maxSize= max(maxSize, dp[i][j]);
				}
			}
		}

		return maxSize;
    }
};

// 4. Space Optimized: 2*O(m)
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix) {
		int maxSize= 0;
		vector<int> curr(m+1, 0);
		vector<int> next(m+1, 0);

		for(int i=n-1; i>=0; i--) {
			for(int j=m-1; j>=0; j--) {
				int right= curr[j+1];
				int diagonal= next[j+1];
				int down= next[j];

				if(matrix[i][j] == 1) {
					curr[j]= 1 + min(right, min(diagonal, down));
					maxSize= max(maxSize, curr[j]);
				} else {
				    curr[j]= 0;
				}
			}

		    next= curr;
		}

		return maxSize;
    }
};

// 5. Ultra Space Optimized: O(1)
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix) {
		int maxSize= 0;

		for(int i=n-1; i>=0; i--) {
			for(int j=m-1; j>=0; j--) {
				int right= j<m-1? matrix[i][j+1]: 0;
				int diagonal= i<n-1 && j<m-1? matrix[i+1][j+1]: 0;
				int down= i<n-1? matrix[i+1][j]: 0;

				if(matrix[i][j] == 1) {
					matrix[i][j]= 1 + min(right, min(diagonal, down));
					maxSize= max(maxSize, matrix[i][j]);
				} else {
				    matrix[i][j]= 0;
				}
			}
		}

		return maxSize;
    }
};
