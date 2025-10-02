#include<iostream>
#include<vector>
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
vector<int> printLikeAWave(int arr[m][n]) {
    vector<int> ans;
    for(int j=0; j<n; j++) {
        if(j&1) {
            for(int i=m-1; i>=0; i--) 
                ans.push_back(arr[i][j]);
        } else {
            for(int i=0; i<m; i++)
                ans.push_back(arr[i][j]);
        }
    }
    return ans;
}

int main() {
    system("cls");

    int arr[m][n];
    inputMatrix(arr);
    vector<int> ans= printLikeAWave(arr);

    for(auto i:ans)
        cout << i << " ";
    cout << endl;

    cout << endl;
    return 0;
}