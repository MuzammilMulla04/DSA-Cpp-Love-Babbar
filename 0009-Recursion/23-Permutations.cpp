#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        ans.push_back(nums);
        return ;
    }

    for(int i=index; i<nums.size(); i++) {
        swap(nums[i], nums[index]);

        solve(nums, index+1, ans);
//BackTracking
        swap(nums[i], nums[index]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index=0;
    solve(nums, index, ans);
    return ans;
}

int main() {
    system("cls");

    int size;
    cout << "Enter Size: ";
    cin >> size;

    vector<int> nums(size);

    cout << "Enter Elements: ";
    for(int i=0; i<size; i++)
        cin >> nums[i];

    vector<vector<int>> ans= permute(nums);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
 
    cout << endl;
    return 0;
}