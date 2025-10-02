#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix, int rows, int cols) {
    cout << endl;
    cout << "Final:-" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void setZeroes(vector<vector<int>> matrix) {
    int m= matrix.size();
    int n= matrix[0].size();

//Check for Zeroes in 1st row & col
    bool rowZero= false, colZero= false;
    for(int i=0; i<m; i++) {
        if(matrix[i][0] == 0) {
            colZero= true;
            break;
        }
    }
    for(int j=0; j<n; j++) {
        if(matrix[0][j] == 0) {
            rowZero= true;
            break;
        }
    }

// Traverse and update 1st row & col on finding '0' respectively
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0]= 0;
                matrix[0][j]= 0;
            }
        }
    }

// Use 1st row & col to set Zeroes
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j]= 0;
        }
    }

//Update 1st row & col to zeroes, if bools
    if(rowZero) {
        for(int j=0; j<n; j++)
            matrix[0][j]= 0;
    }
    if(colZero) {
        for(int i=0; i<m; i++)
            matrix[i][0]= 0;
    }

    printMatrix(matrix, m, n);
}
void setZeroesGPT(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;
// Check if the first row contains zero
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
// Check if the first column contains zero
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
// Use the first row and first column to mark zero locations
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
// Set zeros based on markings in the first row and first column
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
// Set zeros for the first row and first column if needed
    if (firstRowZero) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }

    printMatrix(matrix, rows, cols);
}

int main() {
    system("cls");

    int rows, cols;
    cout << "Enter rows & cols: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    cout << "Enter Matrix:-" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << endl;

    cout << "Intial:- ";
    printMatrix(matrix, rows, cols);

    setZeroes(matrix);
    setZeroesGPT(matrix);

    cout << endl;
    return 0;
}