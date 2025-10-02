#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

//Bit Masking (My Try)
vector<int> givebitMask(int n, int size) {
    vector<int> ans;
//Finding Binary(reversed)
    while(n!=0) {
        if(n&1)
            ans.push_back(1);
        else
            ans.push_back(0);
        n/=2;
    }
//Padding start with 0's
    while(ans.size() < size)
        ans.push_back(0);
//Reversing to get actual binary
    int i=0, j=size-1;
    while(i<j)
        swap(ans[i++],ans[j--]);
    
    return ans;
}
vector<int> giveSubset(vector<int> set, vector<int> bitMask) {
    vector<int> subset;
    for(int i=0; i<set.size(); i++) {
        if(bitMask[i])
            subset.push_back(set[i]);
    }
    return subset;
}
vector<vector<int>> subsetsByBitManipulation(vector<int> nums) { 
    int length= nums.size();
    int noOfSubsets= pow(2,length);
    vector<vector<int>> ans;

    for(int subsetNo=1; subsetNo<noOfSubsets; subsetNo++) {
        vector<int> bitMask= givebitMask(subsetNo, length);
        vector<int> subset= giveSubset(nums, bitMask);

        ans.push_back(subset);
    }

    return ans;
}
//Optimized Bit-Masking
vector<vector<int>> subsetsByBitManipulationOptimized(vector<int> nums) { 
    int length= nums.size();
    int noOfSubsets= pow(2,length);
    vector<vector<int>> ans;

    for(int subsetNo=1; subsetNo<noOfSubsets; subsetNo++) {
        vector<int> subset;
        for(int i=0; i<length; i++) {
            if(subsetNo & (1<<i))
                subset.push_back(nums[i]);
        }
        ans.push_back(subset);
    }

    return ans;
}

//Recursion
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        // if(output.size() != 0)  // For Non-Empty Subsets!
        ans.push_back(output);
        return;
    }

// exclude
    solve(nums, output, index+1, ans);
// include
    output.push_back(nums[index]);
    solve(nums, output, index+1, ans);
}
vector<vector<int>> subsetsByRecursion(vector<int> nums) {
    vector<vector<int>> ans;
    int index=0;
    vector<int> output;
    solve(nums, output, index, ans);
    return ans;
}

void print(vector<vector<int>> ans) {
    cout << "Subsets are:-" << endl;
    for(int i=0; i<ans.size(); i++) {
        for(auto j:ans[i])
            cout << j << " ";
        cout << endl;
    }
}
int main() {
    system("cls");

    int n;
    vector<int> arr;
    
    cout << "Enter Size: ";
    cin >> n;

    cout << "Enter Elements: ";
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    // vector<vector<int>> ans1= subsetsByBitManipulation(arr);
    vector<vector<int>> ans1= subsetsByBitManipulationOptimized(arr);
    // vector<vector<int>> ans2= subsetsByRecursion(arr);
    
    print(ans1);
    // print(ans2);

    cout << endl;
    return 0;
}