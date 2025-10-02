#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m= matrix.size();
    int n= matrix[0].size();

    int start= 0, end= m-1;
// Find Correct Row: BS in Last Col
    while(start<end) {
        int mid= start+ (end-start)/2;
        
        if(matrix[mid][n-1] == target)
            return true;
        else if(matrix[mid][n-1] < target)
            start= mid+1;
        else
            end= mid;
    }

    int row= start;
    start= 0, end= n-1;
// Find Target: BS in Correct Row
    while(start <= end) {
        int mid= start+ (end-start)/2;
        
        if(matrix[row][mid] == target)
            return true;
        else if(matrix[row][mid] < target)
            start= mid+1;
        else
            end= mid-1;
    }

    return false;
}