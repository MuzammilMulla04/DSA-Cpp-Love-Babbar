#include<iostream>
using namespace std;

int FloorSquareRoot(int n) {
	int start= 0, end= n;
	int ans= -1;

	while(start<=end) {
		int mid= start + (end-start)/2;
		int square= mid*mid;
		if(square == n)
			return mid;
		else if(square > n)
			end= mid-1;
		else {
			ans= mid;
			start= mid+1;
		}
	}
	return ans;
}
double Precision(int n, int precisionPoint, int floorSquareRoot) {
	double factor= 1;
	double ans= floorSquareRoot;

	for(int i=0; i<precisionPoint; i++) {
		factor/=10;
		for(double j= ans; j*j<=n; j+=factor) {
			ans= j;
		}
	}
	return ans;
}
double SquareRoot(int n) {
	return Precision(n, 3, FloorSquareRoot(n));
}

int main() {
	system("cls");

	int n;
	cout << "Enter Number: ";
	cin >> n;

	double squareRoot= SquareRoot(n);

	if(squareRoot != -1)
		cout << "Square root of " << n << " is: " << squareRoot;

	system("pause>0");
	cout << endl;
	return 0;
}