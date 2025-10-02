#include<bits/stdc++.h>
using namespace std;

int makeBeautiful(string str) {
    int n= str.size();
    int count= 0, swapCount= 1;
    bool flag= str[0] - '0';
	
    for(int i=1; i<n; i++) {
        flag= !flag;

        if(str[i] - '0' == flag) {
            swapCount++;
        } else {
            count++;
        }
    }

    return min(count, swapCount);
}