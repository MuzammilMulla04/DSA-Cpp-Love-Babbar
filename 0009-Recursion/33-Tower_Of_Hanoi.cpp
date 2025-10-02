#include <bits/stdc++.h>
using namespace std;

void moveDisks(int noOfDisks, vector<vector<int>>& moves, int source, int destination, int auxillary) {
// If there is only one disk, simply move it from the source rod to the destination rod
    if(noOfDisks == 1) {
        moves.push_back({source, destination});
        return;
    }
// Move n-1 disks from source to auxiliary, using destination as auxiliary
    moveDisks(noOfDisks-1, moves, source, auxillary, destination);
// Move the nth disk from source to destination
    moves.push_back({source, destination});
// Move n-1 disks from auxiliary to destination, using source as auxiliary
    moveDisks(noOfDisks-1, moves, auxillary, destination, source);
}

vector<vector<int>> towerOfHanoi(int n) {
    vector<vector<int>> moves;
    moveDisks(n, moves, 1, 2, 3);
    return moves;
}