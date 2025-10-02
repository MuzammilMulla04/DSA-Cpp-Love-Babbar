#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
	int n=arr.size();
	int noOfBeautifulTriplets=0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[j] - arr[i] == d) {
				for(int k= j+1; k<n; k++) {
					if(arr[k] - arr[j] == d)
						noOfBeautifulTriplets++;
				}
			}
		}
	}
	return noOfBeautifulTriplets;
}

int main() {
	system("cls");
	
	int n, d;
	
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter d: ";
	cin >> d;

	vector<int> arr(n);
	cout << "Enter Elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int noOfBeautifulTriplets= beautifulTriplets(d, arr);

	cout << "No. of Beautiful Triplets: "<< noOfBeautifulTriplets << endl;

	cout << endl;
	return 0;
}