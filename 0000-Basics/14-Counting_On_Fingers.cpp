/* Counting on fingers

Problem Statement
A girl counts on her fingers by counting 1 on her thumb, 2 on her index finger, 3 on her middle finger, 4 on her ring finger, 5 on her little finger, 6 on her ring finger, 7 on her middle finger, 8 on her index finger, and 9 on her thumb. She continues in this way indefinitely.

You are given a function,
    int CountingonFingers (int n);

The function takes a number 'n' as input and returns which finger the girl will be on when her count reaches 'n'. return-
    if thumb then return 1,
    if index finger then return 2,
    if middle finger then return 3,
    if ring finger then retum 4,
    and if little finger then return 5

Example:
    Input: 32
    Output: 2
    Explanation: 32 will fall on the index finger, hence the output is 2
 */
#include<bits/stdc++.h>
using namespace std;

int countingOnFingers(int n) {
    vector<int> hash= {1, 2, 3, 4, 5, 4, 3, 2};
    return hash[n%8] + 1;
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans= countingOnFingers(n);
    cout << "Ans: " << ans << endl;

    return 0;
}