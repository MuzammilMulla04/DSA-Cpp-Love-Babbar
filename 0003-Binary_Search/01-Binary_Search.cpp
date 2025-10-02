#include<iostream>
using namespace std;
void SortArray(int a[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i] > a[j]) {
				int temp= a[i];
				a[i]= a[j];
				a[j]= temp;
			}
		}
	}
}
int BinarySearch(int a[], int n, int key) {
	int beg= 0, end= n-1;

	SortArray(a, n);
	cout << "\nSorted Array:-\n";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;

	while(beg<=end) {
		int mid= beg+(end-beg)/2;

		if(a[mid] == key)
			return mid;
		else if(a[mid] < key)
			beg= mid+1;
		else
			end= mid-1;
	}
	return -1;
}

int main() {
	int n;
	cout << "Enter Size: ";
	cin >> n;

	int a[n];
	cout << "Enter Elements: ";
	for(int i=0; i<n; i++)
		cin >> a[i];

	int key;
	cout << "Enter Key: ";
	cin >> key;

	int pos= BinarySearch(a, n, key);
	if(pos != -1)
		cout << "\nFound at index: " << pos;
	else
		cout << "\nNot Found";

	system("pause>0");
	return 0;
}