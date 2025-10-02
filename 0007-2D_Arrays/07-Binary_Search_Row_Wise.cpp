#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
const int row=3, col=3;

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
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
bool binarySearchRowWise(vector<vector<int>> matrix, int target) {
    int start=0, end=row*col-1;
    while(start<=end) {
        int mid= start + (end-start)/2;
        cout << "mid: " << mid << endl;
        int element= matrix[mid/col][mid%col];
        cout << "element: " << element << endl;
        if(element == target) {
            return true;
        } else if(element < target) {
            start= mid+1;
            cout << "start: " << start << endl;
        } else {
            end= mid-1;
            cout << "end: " << end << endl;
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

    if(binarySearchRowWise(matrix, target))
        cout << target << " is present!" << endl;
    else
        cout << target << " is not present!" << endl;
    
    cout << "Bye!" << endl;
    return 0;
}