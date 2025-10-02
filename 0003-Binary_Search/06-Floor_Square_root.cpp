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
int main() {
	system("cls");

	int n;
	cout << "Enter Number: ";
	cin >> n;

	int floorsquareRoot= FloorSquareRoot(n);

	if(floorsquareRoot != -1)
		cout << "Square root of " << n << " is: " << floorsquareRoot;

	system("pause>0");
	cout << endl;
	return 0;
}