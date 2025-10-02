#include<iostream>
using namespace std;

int main() {
    system("cls");

    int arr[3][3];

//Row-wise Input
    cout << "Enter Matrix:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cin >> arr[i][j];
    }
//Print Output
    cout << "Matrix is:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
//Column-wise Input
    cout << "Enter Matrix:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cin >> arr[j][i];
    }
//Print Output
    cout << "Matrix is:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    int arr1[3][3]= {1,2,3,4,5,6,7,8,9};
    cout << "Single-listed Matrix is:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cout << arr1[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    int arr2[3][3]= {{1,4,7}, {2,5,8}, {3,6,9}};
    cout << "Row-Wise listed Matrix is:-" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) 
            cout << arr2[i][j] << " ";
        cout << endl;
    }


    cout << endl;
    return 0;
}