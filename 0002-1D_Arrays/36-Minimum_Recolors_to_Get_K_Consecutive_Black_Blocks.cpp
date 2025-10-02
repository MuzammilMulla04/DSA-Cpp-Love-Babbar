#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int minMoves = 0;
        int moves = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W')
                ++moves;
        }
        minMoves = moves;
        for (int i = k; i < n; ++i) {
            if (blocks[i] == 'W')
                ++moves;
            if (blocks[i - k] == 'W') {
                --moves;
                if (moves < 0)
                    moves = 0;
            }

            minMoves = min(minMoves, moves);
        }

        return minMoves;
    }
};