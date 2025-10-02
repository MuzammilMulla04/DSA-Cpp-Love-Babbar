#include <iostream>
using namespace std;

void merge(int* arr, int start, int end) {
    int mid= start+ (end-start)/2;
    int length1= mid-start+1;
    int length2= end-mid;

    int* arr1= new int[length1];
    int* arr2= new int[length2];

    int index= start;
    for(int i=0; i<length1; i++)
        arr1[i]= arr[index++];
    index= mid+1;
    for(int i=0; i<length2; i++)
        arr2[i]= arr[index++];

    index= start;
    int index1=0;
    int index2=0;
    
    while(index1 < length1 && index2 < length2) {
        if(arr1[index1] < arr2[index2])
            arr[index++]= arr1[index1++];
        else
            arr[index++]= arr2[index2++];
    }
        
    while(index1 < length1)
            arr[index++]= arr1[index1++];

    while(index2 < length2)
            arr[index++]= arr2[index2++];

    delete []arr1;
    delete []arr2;
}

void mergeInPlace(int* arr, int start, int end) {
    int mid= start+ (end-start)/2;
    int i=start, j=mid+1;

    while(i<=mid && j<=end) {
        if(arr[i] > arr[j]) {
            int temp= arr[j];

            for(int k=j; k>i; k--)
                arr[k]= arr[k-1];
            arr[i]= temp;

            i++;
            j++;
        } else {
            i++;
        }
    }
}
void mergeSort(int* arr, int start, int end) {
    if(start >= end)
        return;

    int mid= start+ (end-start)/2;

// Left Part
    mergeSort(arr, start, mid);
// Right Part
    mergeSort(arr, mid+1, end);
// Merge Both Parts
    // merge(arr, start, end);
    mergeInPlace(arr, start, end);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    int* arr= new int[n];

    cout << "Enter Elements:-" << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << endl;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete []arr;

    cout << endl;
    return 0;
}