#include<iostream>
using namespace std;

void dynamicMemoryAllocation() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    int *arr= new int[n];
    // int *arr -- 4(32 bit) or 8(64 bit) bytes -- STACK memory -- STATIC
    // new int[n] -- n*4 bytes -- HEAP memory -- DYNAMIC

    cout << "Enter Elements of Array:-" << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int sum=0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    cout << "Sum of Array: " << sum << endl;
}
void shaytaniPlusPlus() {
// Which  is Dangerous?
    //Case 1:
    while(true) {
        int i=5;
        int arr[5];
// i gets destroyed after every iteration. So, only 1 int memory allocation overall
    }

    //Case 2:
    while(true) {
        int *i= new int;
        int *arr= new int[5];
// *i-- 4/8 bytes -- STACK memory gets freed automatically in each iteration
// new int -- 4 bytes -- HEAP memory must be freed explicitly, elsewhere... 4+4+4+4.... *program crashes*
        delete i;
        delete []arr;
    }
}
int main() {
    system("cls");

    dynamicMemoryAllocation();
    // shaytaniPlusPlus();

    cout << endl;
    return 0;
}