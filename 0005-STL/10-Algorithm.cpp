#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    system("cls");

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int value;
    cout << "Enter Value: ";
    cin >> value;
//binary search
    if(binary_search(v.begin(), v.end(), value))
        cout << value << " is found!" << endl;
    else
        cout << value << " is not found!" << endl;
//lower & upper bound
    cout << "Lower Bound: " << lower_bound(v.begin(), v.end(), value) - v.begin() << endl;
    cout << "Upper Bound: " << upper_bound(v.begin(), v.end(), value) - v.begin() << endl;
//max & min in vectors
    cout << "Max of " << *v.begin() << " and " << v.end() - v.begin() << " is: " << max(*v.begin(), v.end() - v.begin()) << endl;
    cout << "Min of " << *v.begin() << " and " << v.end() - v.begin() << " is: " << min(*v.begin(), v.end() - v.begin()) << endl;

    int a= 8, b= 5;
//max & min
    cout << "Max: " << max(a, b) << endl;
    cout << "Min: " << min(a, b) << endl;
//swap
    swap(a, b);
    cout << "After swapping:-" << endl;
    cout << "A: " << a << endl << "B: " << b << endl;
//reverse
    string str= "String";
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
//rotate
    rotate(v.begin(), v.begin()+2, v.end());
    cout << "After Rotating:-" << endl;
    for(auto i:v)
        cout << i << " ";
    cout << endl;
//Intro sort
    sort(v.begin(), v.end());
    cout << "After Sorting:-" << endl;
    for(auto i:v)
        cout << i << " ";
    cout << endl;

    cout << endl;
    return 0;
}