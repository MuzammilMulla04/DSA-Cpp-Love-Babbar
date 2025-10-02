#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	for(int i=0; i<n-1; i++) {
		bool isSwapped= false;
		for(int j=0; j<n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				isSwapped= true;
			}
		}
		if(!isSwapped)
			break;
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

	bubbleSort(arr, n);
	cout << endl << "Sorted Array:-" << endl;
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	system("pause>0");
	cout << endl;
	return 0;
}