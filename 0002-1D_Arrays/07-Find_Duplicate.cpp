#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n){
	int freq[n+1]= { 0 };
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;

        if(freq[arr[i]] > 1)
            return arr[i];
    }
}

int main() {
    system("cls");
    int size, array[100];

    cout << "Enter Size: ";
    cin >> size;

    cout << "Enter Elements: ";
    for(int i=0; i< size; i++)
        cin >> array[i];

    cout << "\nDuplicate Element is: " << findDuplicate (array, size);
}