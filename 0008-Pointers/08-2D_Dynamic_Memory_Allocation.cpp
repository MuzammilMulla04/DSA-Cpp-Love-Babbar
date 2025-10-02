#include<iostream>
using namespace std;

void dynamic2dMemoryAllocation() {
    int rows, cols;

    cout << "Enter rows & columns for matrix: ";
    cin >> rows >> cols;

    int** matrix= new int* [rows];
    for(int i=0; i<rows; i++)
        matrix[i]= new int[cols];

    cout << "Enter Matrix:-" << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            cin >> matrix[i][j];
    }

    cout << "Matrix is:-" << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    for(int i=0; i<rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}
void jaggeredArray() {
    int rows;
    cout << "Enter Rows: ";
    cin >> rows;

    int** arr= new int*[rows];
    for(int i=0; i<rows; i++)
        arr[i]= new int[i];

    for(int i=0; i<rows; i++) {
    cout << "Enter " << i+1 << " Elements: ";
        for(int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    cout << endl;

    cout << "Array is:-" << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<=i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    system("cls");

    // dynamic2dMemoryAllocation();
    jaggeredArray();

    cout << endl;
    return 0;
}