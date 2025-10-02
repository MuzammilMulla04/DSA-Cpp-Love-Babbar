#include<iostream>
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
bool isPresent(int arr[m][n], int target) {
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if(arr[i][j] == target)
                return true;
        }
    }
    return false;
}

int main() {
    system("cls");

    int arr[m][n];
    inputMatrix(arr);
    outputMatrix(arr);

    int target;
    cout << "Enter element to be searched: ";
    cin >> target;

    if(isPresent(arr, target))
        cout << target << " is found!";
    else
        cout << target << " is not found!";

    cout << endl;
    return 0;
}