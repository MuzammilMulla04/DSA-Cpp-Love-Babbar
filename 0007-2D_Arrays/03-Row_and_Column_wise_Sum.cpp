#include<iostream>
#include<limits.h>
using namespace std;
const int m=3, n=3;
void inputMatrix(int arr[m][n]) {
    cout << "Enter Matrix:-" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) 
            cin >> arr[i][j];
    }
    cout << endl;
}
void outputMatrix(int arr[m][n]) {
    cout << "Matrix is:-" << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void rowWiseSum(int arr[m][n]) {
    for(int i=0; i<m; i++) {
        int sum=0;
        for(int j=0; j<n; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of Row " << i+1 << " is: " << sum << endl;
    }
}
void columnWiseSum(int arr[m][n]) {
    for(int j=0; j<n; j++) {
        int sum=0;
        for(int i=0; i<n; i++) {
            sum += arr[i][j];
        }
        cout << "Sum of Column " << j+1 << " is: " << sum << endl;
    }
}
void largestRowSum(int arr[m][n]) {
    int maxRowSum=INT_MIN;
    int maxRowIndex=0;
    for(int i=0; i<m; i++) {
        int rowSum=0;
        for(int j=0; j<n; j++)
            rowSum += arr[i][j];

        if(maxRowSum < rowSum) {
            maxRowSum= rowSum;
            maxRowIndex= i;
        }
    }
    cout << "Maximum Row Sum is: " << maxRowSum << endl << "At Row: " << maxRowIndex << endl;
}

int main() {
    system("cls");

    int arr[m][n];
    inputMatrix(arr);
    outputMatrix(arr);

    rowWiseSum(arr);
    columnWiseSum(arr);

    largestRowSum(arr);

    cout << endl;
    return 0;
}