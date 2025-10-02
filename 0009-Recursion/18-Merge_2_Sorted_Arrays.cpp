#include <iostream>
using namespace std;

void mergeGPT(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;
    int m = mid - start + 1;
    int n = end - mid;

    int index1 = start;
    int index2 = mid + 1;

    while (index1 <= mid && index2 <= end) {
        if (arr[index1] > arr[index2]) {
            // Shift elements to make space for the element from the right side
            int temp = arr[index2];
            for (int i = index2; i > index1; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index1] = temp;

            // Update indices
            index1++;
            mid++;
            index2++;
        } else {
            index1++;
        }
    }
}

void merge(int arr[], int start, int end) {
    int mid= start+(end-start)/2;
    int m= mid-start+1;
    int n= end-mid;

    int index= start;
    int index1= 0;
    int index2= m;

    while(index1 < m && index2 < n) {
        if(arr[index1] > arr[index2])
            swap(arr[index1++], arr[index2]);
        else
            index2++;
    }

    index2= m;
    while(index1 < m) {
        swap(arr[index1++], arr[index2]);
    }
}
void mergeSort(int arr[], int start, int end) {
    if(start >= end)
        return ;
    int mid= start+(end-start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    mergeGPT(arr, start, end);
}
void merge2SortedArrays(int arr1[], int arr2[], int m, int n) {
    for(int i=m, j=0; i<m+n; i++, j++)
        arr1[i]= arr2[j];
    
    mergeSort(arr1, 0, m+n-1);
}

int main() {
    system("cls");

    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    int* arr1= new int[m+n];
    int* arr2= new int[n];

    cout << "Enter Elements of arr1:-" << endl;
    for(int i=0; i<m+n; i++)
        cin >> arr1[i];
    cout << "Enter Elements of arr2:-" << endl;
    for(int i=0; i<n; i++)
        cin >> arr2[i];
    cout << endl;

    merge2SortedArrays(arr1, arr2, m, n);

    for(int i=0; i<m+n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    delete []arr1;
    delete []arr2;

    cout << endl;
    return 0;
}