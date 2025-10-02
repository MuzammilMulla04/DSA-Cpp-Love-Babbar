/*
Given an integer array nums of length n
where all the integers of nums are in the range [1, n]
and each integer appears once or twice.
Return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time
and uses only constant extra space. (NEGLECTING)

Input: nums [4, 3, 2, 7, 8, 2, 3, 1]
Output: [2, 3]

Input: nums [1, 1, 2]
Output: [1]

Input: nums = [1]
Output: []
*/

#include<iostream>
using namespace std;

int Find_Duplicates(int nums[], int n, int ans[]) {     // O(n^2)
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i] == nums[j]) {
                ans[i] = nums[i];
                break;
            }
        }
    }
}

int main() {
    system("cls");
    int n;

    cout << "Enter Size: ";
    cin >> n;

    int nums[n]= { 0 };
    cout << "Enter Elements: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    
    int ans[n]= { 0 };
    Find_Duplicates(nums, n, ans);

    cout << "Duplicates are: ";    
    for(int i=0; i<n; i++) {
        if(ans[i] != 0)
            cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}