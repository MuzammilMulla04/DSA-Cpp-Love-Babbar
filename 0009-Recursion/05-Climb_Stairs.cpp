#include<iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    return countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
}

int main() {
    system("cls");

    int nStairs;
    cout << "No. of Stairs: ";
    cin >> nStairs;

    cout << "No. of ways to climb " << nStairs << " stairs is: " << countDistinctWays(nStairs) << endl;

    cout << endl;
    return 0;
}