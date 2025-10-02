#include <bits/stdc++.h> 
using namespace std;

bool canPlacePlayers(vector<int>& positions, int c, int mid) {
	int count= 1;
	int lastPos= positions[0];

	for(int& position: positions) {
		if(position - lastPos >= mid) {
			count++;
			lastPos= position;

			if(count == c)
				return true;
		}
	}

	return false;
}
int chessTournament(vector<int> positions, int n, int c) {
	sort(positions.begin(), positions.end());

	int start= 1;
	int end= positions[n-1] - positions[0];

	int focus= INT_MIN;
	while(start <= end) {
		int mid= start + (end-start)/2;

		if(canPlacePlayers(positions, c, mid)) {
			focus= mid;
			start= mid+1;
		} else {
			end= mid-1;
		}
	}

	return focus;
}