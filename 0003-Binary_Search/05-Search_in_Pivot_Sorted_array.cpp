#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int findPivot(vector<int>& arr) {
        int n= arr.size();
        if(arr[0] < arr[n-1])
            return 0;
        
        int start= 0, end= n-1;
        while(start < end) {
            int mid= start + (end-start)/2;

            if(arr[mid] >= arr[0])
                start= mid+1;
            else
                end= mid;
        }

        return start;
    }
    int binarySearch(vector<int>& arr, int start, int end, int target) {
        while(start <= end) {
            int mid= start + (end-start)/2;

            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                start= mid+1;
            else
                end= mid-1;
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivot= findPivot(nums);

        int start= 0, end= n-1;
        if(pivot != 0) {
            if(target >= nums[0])
                end= pivot-1;
            else
                start= pivot;
        }
        return binarySearch(nums, start, end, target);
    }
};

int main() {
	system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements: ";
    for (int& i : arr)
        cin >> i;

	int key;
	cout << "Enter element to be found: ";
	cin >> key;

	Solution s;
	int pos= s.search(arr, key);

	if(pos == -1)
		cout << "Element cannot be found!";
	else
		cout << "Element found at index position: " << pos;

	cout << endl;
	return 0;
}
