#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int index, int sum, int target, vector<int> output, vector<vector<int>>& ans) {
    if (index >= arr.size()) {
        if (sum == target) {
            ans.push_back(output);
        }
        return;
    }
    
    solve(arr, index+1, sum, target, output, ans);

    output.push_back(arr[index]);
    solve(arr, index+1, sum+arr[index], target, output, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(arr, 0, 0, k, output, ans);
    return ans;
}

int main() {
    system("cls");

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements: ";
    for(int& i: arr) {
        cin >> i;
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> ans= findSubsetsThatSumToK(arr, n, k);

    cout << "Subsets:-" << endl;
    for(int i=0; i<ans.size(); i++) {
        for(auto j: ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}