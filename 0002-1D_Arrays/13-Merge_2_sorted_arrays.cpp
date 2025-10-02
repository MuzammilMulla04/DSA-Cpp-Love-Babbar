#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i= m-1, j=n-1;
    int index= m+n-1;

    while(i>=0 && j>=0) {
        if(nums1[i] < nums2[j])
            nums1[index--]= nums2[j--];
        else
            nums1[index--]= nums1[i--];
    }

    while(j>=0) {
        nums1[index--]= nums2[j--];
    }
}

int main() {
    system("cls");

    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    vector<int> nums1(m+n, 0), nums2(n);
    cout << "Enter Elements of Nums1: ";
    for(int i=0; i<m; i++) {
        cin >> nums1[i];
    }
    cout << "Enter Elements of Nums2: ";
    for(int& i: nums2)
        cin >> i;
    cout << endl;
    
    merge(nums1, m, nums2, n);
    cout << "Merged Array Nums1: ";
    for(int& i: nums1)
        cout << i << " ";

    cout << endl;
    return 0;
}