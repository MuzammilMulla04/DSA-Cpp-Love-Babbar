#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[index] = nums[i];
            index++;
        } else {
            zeroCount++;
        }
    }

    while (index < n) {
        nums[index] = 0;
        index++;
    }
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    vector<int> nums(n, 0);
    cout << "Enter Elements: ";
    for (int& num : nums) {
        cin >> num;
    }

    moveZeroes(nums);

    cout << "Ans:- " << endl;
    for (int& num : nums)
        cout << num << " ";

    cout << endl;
    return 0;
}