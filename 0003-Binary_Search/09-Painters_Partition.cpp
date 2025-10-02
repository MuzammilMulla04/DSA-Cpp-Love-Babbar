#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
	int studentCount=1;
	int pageSum=0;

	for(int i=0; i<n; i++) {
		if(pageSum + arr[i] <= mid) {
			pageSum += arr[i];
		}
		else {
			studentCount++;
			if(studentCount > m || arr[i] > mid)
				return false;
			pageSum= arr[i];
		}
	}
	return true;
}
int painterPartition(int arr[], int n, int m) {
	if(n<m)
		return -1;
	int start=0;
	int end;
	for(int i=0; i<n; i++) {
		end += arr[i];
	}
	int ans= -1;

	while(start<=end) {
		int mid= start + (end-start)/2;
		if(isPossible(arr, n, m, mid)) {
			ans= mid;
			end= mid-1;
		}
		else {
			start= mid+1;
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

	int arr[n];
	cout << "Enter Elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	cout << "Minimum Time: " << painterPartition(arr, n, m) << endl;

	system("pause>0");
	cout << endl;
	return 0;
}