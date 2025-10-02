#include<iostream>
using namespace std;

int Bubble(int stalls[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i; j++) {
			if(stalls[j] > stalls[j+1]) {
				int temp= stalls[j];
				stalls[j]= stalls[j+1];
				stalls[j+1]= temp;
			}
		}
	}
}
bool isPossible(int stalls[], int n, int k, int mid) {
	int cowsCount=1;
	int lastPos=stalls[0];

	for(int i=0; i<n; i++) {
		if(stalls[i] - lastPos >= mid) {
			cowsCount++;
			if(cowsCount == k)
				return true;
			lastPos= stalls[i];
		}
	}
	return false;
}
int aggressiveCows(int stalls[], int n, int k) {
	if(n<k)
		return -1;

	Bubble(stalls, n);

	int start=0, end= stalls[n-1];
	int ans= -1;

	while(start<=end) {
		int mid= start + (end-start)/2;
		if(isPossible(stalls, n, k, mid)) {
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
	cout <<" Enter n: ";
	cin >> n;
	cout <<" Enter m: ";
	cin >> m;

	int stalls[n];
	cout << "Enter Elements: ";
	for(int i=0; i<n; i++)
		cin >> stalls[i];

	cout << "Maximum distance between any two aggressive cows: " << aggressiveCows(stalls, n, m) << endl;

	system("pause>0");
	cout << endl;
	return 0;
}