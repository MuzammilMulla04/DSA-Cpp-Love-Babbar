#include<iostream>
#include<limits.h>
using namespace std;

int max_Array(int array[], int size) {
	int Max= INT_MIN;
    for(int i=0; i<size; i++)
    	Max = max(Max, array[i]);
    return Max;
}
int min_Array(int array[], int size) {
	int Min= INT_MAX;
    for(int i=0; i<size; i++)
    	Min = min(Min, array[i]);
    return Min;
}

int main()
{
    int size, array[10];
    cout << "Enter Size of Array: ";
    cin >> size;
    cout << "Enter Elements: ";
    for(int i=0; i<size; i++)
		cin >> array[i];
    
	int max = max_Array(array, size);
	int min = min_Array(array, size);

    cout << "\nMaximum element in the Array is: " << max;
    cout << "\nMinimum element in the Array is: " << min;
}