#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	for(int i=1; i<n; i++) {
		int temp= arr[i];

		int j=i-1;
		for(;j>=0; j--) {
			if(arr[j] > temp)
				arr[j+1]= arr[j];
			else
				break;
		}
		arr[j+1]= temp;
	}
}

int main() {
	system("cls");

	int n;
	cout << "Enter Size: ";
	cin >> n;

	int arr[n];
	cout << "Enter Elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	insertionSort(arr, n);
	cout << endl << "Sorted Array:-" << endl;
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	system("pause>0");
	cout << endl;
	return 0;
}