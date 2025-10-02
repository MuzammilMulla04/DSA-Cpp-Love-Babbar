/*
Lumberjacm Mirmo needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can tame down forests lime wildfire. However, Mirmo is only allowed to cut a single row of trees.
Mirmo‟s machine worms as follows: Mirmo sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirmo then tames the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirmo raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirmo will tame 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
Mirmo is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirmo find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input:
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirmo‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirmo will always be able to obtain the required amount of wood.
Output:
The first and only line of output must contain the required height setting.

Example
Input:
4 7
20 15 10 17
Output:
15

Input:
5 20
4 42 40 26 46
Output:
36
*/

// N- No. of Trees
// M- Wood Required
// H- Height of Sawblade
// Help Mirmo find the maximum integer height H of the sawblade that stil allows him to cut off at least M metres of wood.

#include<iostream>
using namespace std;

int Bubble(int trees[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i; j++) {
			if(trees[j] > trees[j+1])
				swap(trees[j], trees[j+1]);
		}
	}
}
bool isPossible(int trees[], int n, int m, int mid) {
	int wood=0;
	for(int i=0; i<n; i++) {
		if(trees[i] > mid)
			wood += (trees[i] - mid);
		
		if(wood >= m)
			return true;
	}
	return false;
}
int Eko_Eko(int trees[], int n, int m) {
	int start=0, end= trees[0];
	for(int i=0; i<n; i++)
		end += trees[i];
	int ans= -1;

	while(start<=end) {
		int mid= start + (end-start)/2;
		if(isPossible(trees, n, m, mid)) {
			ans= mid;
			start= mid+1;
		}
		else {
			end= mid-1;
		}
	}
	return ans;
}

int main() {
	system("cls");

	int m, n;
	cout <<" Enter no. of trees: ";
	cin >> n;
	cout <<" Enter metres of wood required: ";
	cin >> m;

	int trees[n];
	cout << "Enter height of trees: ";
	for(int i=0; i<n; i++)
		cin >> trees[i];

	cout << "Maximum height of chainsaw: " << Eko_Eko(trees, n, m) << endl;

	cout << endl;
	return 0;
}