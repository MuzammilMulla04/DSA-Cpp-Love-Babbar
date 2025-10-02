#include<bits/stdc++.h>
#include"Hero.cpp"
using namespace std;

class empty {};


int main() {
    system("cls");

    empty e;
    cout << "Size of Empty Object: " << sizeof(e) << endl;  // 1 byte is allocated for its identification & tracking purposes

    Hero h;     // Creating objects through an external file by including its filename in preprocessor directory

    cout << endl;
    return 0;
}