#include<iostream>
using namespace std;

int main() {
    int a[100]= { 1, 2, 2, 2, 3, 4 };
    int b[100]= { 2, 2, 3, 3 };
    int l=0,m=6,n=4;
    int c[100];

// 2 Pointer Approach
    for(int i=0,j=0; (i<m)&&(j<n);) {
        if(a[i]>b[j])
            j++;
        else if(a[i]<b[j])
            i++;
        else {
            c[l]=a[i];
            l++;
            i++;
            j++;
        }
    }

    if(l==0)
        return -1;
    else {
        cout << "\nIntersection is:-\n";
        for(int i=0; i<l; i++)
            cout << c[i] << " ";
    }

}