#include <bits/stdc++.h>
using namespace std;

/* Greatest Number Possible

Problem Statement
You are given a function,
    char FindMax(int arr[], int size);

The function accepts an integer array arr of length size as its argument. Implement the function to find and return the greatest number possible by rearranging the digits obtained from all the numbers present in the array.

Note: You may need to rearrange the digits of the numbers to form the maximum number.

Example:
    Input:  4
            34 79 58 64
    Output: 98765443
    Explanation:    All digits obtained from all the numbers in the array are 3, 4, 7, 4, 5, 8, 6, 4. The maximum number obtained after rearranging these digits is 98765443.


    Input:  3
            21 90 23
    Output: 932210
*/

string findMax(vector<int>& arr) {
    vector<int> freq(10, 0);
    for(int num: arr) {
        while(num > 0) {
            int digit= num%10;
            num /= 10;

            freq[digit]++;
        }
    }

    string ans= "";
    for(int i=9; i>=0; i--) {
        while(freq[i] > 0) {
            ans += i + '0';
            freq[i]--;
        }
    }

    return ans;
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    vector<int> arr(n);
    for(int& i: arr)
        cin >> i;

    string ans= findMax(arr);
    cout << "Maximum Possible Number: " << ans << endl;

    return 0;
}