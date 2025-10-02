#include<bits/stdc++.h>
using namespace std;

int findMSB(int n) {
    int count= 0;

    while(n>1) {
        n= n>>1;
        count++;
    }

    while(count--)
        n= n<<1;

    return n;
}
int findMSB2(int n) {
    int noOfBits= (log(n)/log(2));
    return pow(2, noOfBits);
}
int findMSB3(int n) {
    cout << "n:\t\t" << bitset<32>(n) << endl;
    n=n | n>>1;
    cout << "n | n>>1:\t" << bitset<32>(n) << endl;
    n=n | n>>2;
    cout << "n | n>>2:\t" << bitset<32>(n) << endl;
    n=n | n>>4;
    cout << "n | n>>4:\t" << bitset<32>(n) << endl;
    n=n | n>>8;
    cout << "n | n>>8:\t" << bitset<32>(n) << endl;
    n=n | n>>16;
    cout << "n | n>>16:\t" << bitset<32>(n) << endl;
    n++;
    cout << "n++:\t\t" << bitset<32>(n) << endl;
    n=n>>1;
    cout << "n>>1:\t\t" << bitset<32>(n) << endl;
    return n;
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans= findMSB3(n);
    cout << "Ans: " << ans << endl;

    cout << endl;
    return 0;
}