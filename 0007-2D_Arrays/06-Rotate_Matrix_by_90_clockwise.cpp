#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
const int m=3, n=3;

vector<vector<int>> inputVectorMatrix() {
    vector<vector<int>> matrix;

    cout << "Enter Vector:-" << endl;
    for(int i=0; i<m; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
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
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
vector<int> rotateMatrixClockwise(vector<vector<int>> matrix) {
    int row= matrix.size();
    int col= matrix[0].size();
    int startingRow=0;
    int startingCol=0;
    int endingRow= row-1;
    int endingCol= col-1;

    while(startingRow <= endingRow && startingCol <= endingCol) {
        //swap top with right
        for(int index1= startingCol, index2= startingRow; index1 <= startingRow-1; index1++, index2++)
            swap(matrix[startingRow][index1], matrix[index2][endingCol]);
        //swap top with bottom
        for(int index1= startingCol, index2= endingCol; index1 <= endingCol-1; index1++, index2--)
            swap(matrix[startingRow][index1], matrix[endingRow][index2]);
        //swap top with left
        for(int index1= startingCol, index2= endingRow; index1 <= endingCol-1; index1++, index2--)
            swap(matrix[startingRow][index1], matrix[index2][startingCol]);
        startingRow++;
        startingCol++;
        endingRow--;
        endingCol--;
    }
}

int main() {
    system("cls");

    vector<vector<int>> matrix= inputVectorMatrix();
    outputVectorMatrix(matrix);

    vector<int> ans= rotateMatrixClockwise(matrix);
    for(auto i:ans)
        cout << i << " ";
    cout << endl;
    
    cout << "Bye!" << endl;
    return 0;
}