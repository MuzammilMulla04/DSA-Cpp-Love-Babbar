#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums) {
    int n = nums.size();

// If there are only two elements rotated once, [13, 11]
    if (n == 2)
        return nums[0] < nums[1] ? 0 : 1;

// If arr is rotated 'n' times => no rotation
    if (nums[0] < nums[n - 1])
        return 0;

// Elsewhere
    int start = 0, end = n - 1;
    while (start < end) {
        int mid = (start + end) / 2;

        if (nums[mid] >= nums[0])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements: ";
    for (int& i : arr)
        cin >> i;

    int pos = findPivot(arr);
    cout << "\nPivot found at index: " << pos;

    return 0;
}