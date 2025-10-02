#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
void print(vector<int> arr) {
	cout << endl;
	for(auto i:arr)
		cout << i << " ";
	cout << endl;
}
vector<int> reverse(vector<int> arr, int n) {
	vector<int> temp;

	for(int i=n-1; i>=0; i--)
		temp.push_back(arr[i]);

	return temp;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i=n-1;
	int j=m-1;
	vector<int> ans;
	int carry=0;
	while(i>=0 && j>=0) {
		int val1= a[i--];
		int val2= b[j--];
		int sum= val1+val2+carry;
		carry= sum/10;
		ans.push_back(sum%10);
	}
//Case 1: i>j
	while(i>=0) {
		int val1= a[i--];
		int sum= val1+carry;
		carry= sum/10;
		ans.push_back(sum%10);
	}
//Case 2: i<j
	while(j>=0) {
		int val2= b[j--];
		int sum= val2+carry;
		carry= sum/10;
		ans.push_back(sum%10);
	}
//Case 3: carry=1
	while(carry != 0) {
		int sum= carry;
		carry= sum/10;
		ans.push_back(sum%10);
	}
	ans= reverse(ans, ans.size());
	return ans;
}

int main() {
    system("cls");

    vector<int> a= {4, 5, 1};
    vector<int> b= {3, 4, 5};
    int n= sizeof(a)/sizeof(int);
    int m= sizeof(b)/sizeof(int);
	 
	vector<int> sum= findArraySum(a, n, b, m);
	print(sum);

 

    cout << endl;
    return 0;
}