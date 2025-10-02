#include<iostream>
using namespace std;

int sum_Array(int array[], int size) {
	int sum = 0;
    for(int i=0; i<size; i++)
    	sum += array[i];
    return sum;
}

int main()
{
    int size, array[10];
    cout << "Enter Size of Array: ";
    cin >> size;
    cout << "Enter Elements: ";
    for(int i=0; i<size; i++)
		cin >> array[i];
    
	int sum = sum_Array(array, size);
    cout << "Sum of Elements in the Array is: " << sum;
}