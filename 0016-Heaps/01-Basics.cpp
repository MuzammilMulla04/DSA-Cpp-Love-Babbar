#include<iostream>
#include<vector>
using namespace std;

class maxHeap {
    int size;
    vector<int> arr;
public:
// Constructor
    maxHeap() {
        size= 0;
        arr.resize(100);
    }
    maxHeap(int size) {
        this->size= size;
        arr.resize(size+1);

        cout << "Enter Elements: ";
        for(int i=1; i<=size; i++)
            cin >> arr[i];
    }
// Insert
    void insert(int value) {
        size++;
        int index= size;
        arr[index]= value;

        while(index>1) {
            int parent= index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index= parent;
            } else {
                return;
            }
        }
    }
// Print
    void print() {
        for(int i=1; i<=size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
// Delete
    void deletefromHeap() {
        if(size == 0)
            return;

        arr[1]= arr[size];
        size--;

        int index= 1;
        while(index < size) {
            int leftIndex= 2*index;
            int rightIndex= 2*index + 1;

            if(leftIndex <= size && arr[leftIndex] > arr[index]) {
                swap(arr[index], arr[leftIndex]);
                index= leftIndex;
            } else if(rightIndex <= size && arr[rightIndex] > arr[index]) {
                swap(arr[index], arr[rightIndex]);
                index= rightIndex;
            } else {
                return;
            }
        }
    }
// Functions
    void heapify(int index) {
        int largest= index;
        int leftIndex= 2*index;
        int rightIndex= 2*index + 1;

        if(leftIndex <= size && arr[leftIndex] > arr[largest])
            largest= leftIndex;
        if(rightIndex <= size && arr[rightIndex] > arr[largest])
            largest= rightIndex;

        if(largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }
    void heapSort() {
        int tempSize= size;

        while(size > 1) {
            swap(arr[size], arr[1]);
            size--;

            heapify(1);
        }

        size= tempSize;
    }
};

int main() {
    system("cls");
/* 
    maxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);

    h.print();

    h.deletefromHeap();
    h.deletefromHeap();

    h.print();
 */
    int n= 5;
    maxHeap h2(n);
    h2.print();

    for(int i= n/2; i>0; i--)
        h2.heapify(i);
    cout << "Before Sorting: ";
    h2.print();

    h2.heapSort();
    cout << "After Sorting: ";
    h2.print();

    return 0;
}