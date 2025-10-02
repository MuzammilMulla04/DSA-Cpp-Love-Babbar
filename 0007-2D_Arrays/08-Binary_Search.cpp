#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
const int row=5, col=5;

vector<vector<int>> inputVectorMatrix() {
    vector<vector<int>> matrix;

    cout << "Enter Vector:-" << endl;
    for(int i=0; i<row; i++) {
        vector<int> temp;
        for(int j=0; j<col; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        matrix.push_back(temp);
    }
    cout << endl;

    return matrix;
}
void outputVectorMatrix(vector<vector<int>> matrix) {
    cout << "Matrix is:-" << endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) 
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}
bool binarySearch(vector<vector<int>> matrix, int target) {
    int rows= matrix.size();
    int cols= matrix[0].size();

    int row= 0;
    int col= cols-1;
    while(row < rows && col >= 0) {
        if(matrix[row][col] == target) {
            return true;
        } else if(matrix[row][col] < target) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}

int main() {
    system("cls");

    vector<vector<int>> matrix= inputVectorMatrix();
    outputVectorMatrix(matrix);

   int target;
    cout << "Enter target: ";
    cin >> target;

    if(binarySearch(matrix, target))
        cout << target << " is present!" << endl;
    else
        cout << target << " is not present!" << endl;
    
    cout << "Bye!" << endl;
    return 0;
}