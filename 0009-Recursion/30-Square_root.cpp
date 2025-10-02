#include<bits/stdc++.h>
using namespace std;

int ifPossible(int start, int end, int n, int ans= -1) {
    if(start >= end)
        return ans;

    int mid= start+ (end-start)/2;

    if(mid*mid == n) {
        return mid;
    }
    else if(mid*mid < n) {
        ans= mid;
        return ifPossible(mid+1, end, n, ans);
    }
    else
        return ifPossible(start, mid, n, ans);
}
int floorSquareRoot(int n) {
    int floorsquareroot= ifPossible(0, n-1, n);
    
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Floor Square Root of " << n << " is: " << floorSquareRoot(n) << endl;

    cout << endl;
    return 0;
}