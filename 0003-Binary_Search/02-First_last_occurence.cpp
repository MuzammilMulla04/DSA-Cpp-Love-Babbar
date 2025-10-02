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
int FirstOccurence(int a[], int n, int key) {
	int beg= 0, end= n-1;
	int ans= -1;

	while(beg<=end) {
		int mid= beg+(end-beg)/2;

		if(a[mid] == key) {
			ans= mid;
			end= mid-1;
		}
		else if(a[mid] < key)
			beg= mid+1;
		else
			end= mid-1;
	}
	return ans;
}
int LastOccurence(int a[], int n, int key) {
	int beg= 0, end= n-1;
	int ans= -1;

	while(beg<=end) {
		int mid= beg+(end-beg)/2;

		if(a[mid] == key) {
			ans= mid;
			beg= mid+1;
		}
		else if(a[mid] < key)
			beg= mid+1;
		else
			end= mid-1;
	}
	return ans;
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

	int f= FirstOccurence(a, n, key);
	int l= LastOccurence(a, n, key);

	cout << "\nFirst Occurence of " << key << " is at index: " << f;
	cout << "\nLast Occurence of " << key << " is at index: " << l;

//	system("pause>0");
	return 0;
}