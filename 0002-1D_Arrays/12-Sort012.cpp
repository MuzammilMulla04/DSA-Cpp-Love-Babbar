#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int freq[3]= { 0 };
    for(int i=0; i<n; i++)
        freq[arr[i]]++;

    int i=0, count=0;
    while(i<n) {
        if(freq[count] != 0) {
            arr[i]= count;
            freq[count]--;
            i++;
        }
        else
            count++;
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

    sort012(arr, n);

    for(int k=0; k<n; k++) 
        cout << arr[k] << " ";

    cout << endl;
    return 0;
}