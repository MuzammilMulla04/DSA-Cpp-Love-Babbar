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
vector<int> Spiral(vector<vector<int>> matrix) {
    vector<int> ans;
    int row= matrix.size();
    int col= matrix[0].size();
    int count= 0;
    int totalNums= col*row;
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    while(count<totalNums) {
        for(int index= startingCol; count<totalNums && index<=endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;
        for(int index= startingRow; count<totalNums && index<= endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
        for(int index= endingCol; count<totalNums && index >= startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;
        for(int index= endingRow; count<totalNums && index >= startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main() {
    system("cls");

    vector<vector<int>> matrix= inputVectorMatrix();
    outputVectorMatrix(matrix);

    vector<int> ans= Spiral(matrix);
    for(auto i:ans)
        cout << i << " ";
    cout << endl;
    
    cout << "Bye!" << endl;
    return 0;
}