#include <iostream>
#include<vector>
using namespace std;

int mergeInPlace(int* arr, int start, int end) {
    int inversionCount = 0;
    int mid = start + (end - start) / 2;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            inversionCount += (mid - i);
            int temp = arr[j];

            for (int k = j; k > i; k--)
                arr[k] = arr[k - 1];
            arr[i] = temp;

            i++;
            j++;
        } else {
            i++;
        }
    }

    return inversionCount;
}
int mergeSort(int* arr, int start, int end) {
    if (start >= end)
        return 0;
    int count = 0;
    int mid = start + (end - start) / 2;

    // Left Part
    count += mergeSort(arr, start, mid);
    // Right Part
    count += mergeSort(arr, mid + 1, end);
    // Merge Both Parts
    // merge(arr, start, end);
    count += mergeInPlace(arr, start, end);

    return count;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter Elements:-" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << endl;

    int noOfInversions = mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "No of Inversions: " << noOfInversions << endl;

    delete[] arr;

    cout << endl;
    return 0;
}

class Solution {
    long long merge(long long arr[], long long start, long long end) {
        if(start >= end)
            return 0;
        
        long long mid= start + (end-start)/2;
        long long count= 0;
        vector<long long> temp;
        
        long long i= start, j= mid+1;
        while(i<=mid && j<=end) {
            if(arr[i] > arr[j]) {
                temp.push_back(arr[j]);
                count += mid-i+1;
                j++;
            } else {
                temp.push_back(arr[i]);
                i++;
            }
        }

        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        i= start;
        for(auto val: temp)
            arr[i++]= val;
        
        return count;
    }
    long long mergeSort(long long arr[], long long start, long long end) {
        if (start >= end)
            return 0;
            
        long long count = 0;
        long long mid = start + (end - start) / 2;

        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid + 1, end);

        count += merge(arr, start, end);

        return count;
    }
public:
    long long inversionCount(long long arr[], long long N) {
        return mergeSort(arr, 0, N-1);
    }
};