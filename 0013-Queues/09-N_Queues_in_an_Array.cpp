#include<bits/stdc++.h>
using namespace std;

class NQueue {
    int *arr, *next;
    int *front, *rear;
    int size, no, freespot;
public:
    NQueue(int n, int k) {
        size= n;
        no= k;
        arr= new int[size];
        next= new int[size];
        for(int i=0; i<size; i++) {
            arr[i]= 0;
            next[i]= i+1;
        }
        next[size-1]= -1;
        freespot= 0;

        front= new int[no];
        rear= new int[no];
        for(int i=0; i<no; i++) {
            front[i]= -1;
            rear[i]= -1;
        }
    }
    bool enqueue(int value, int no) {
        no--;
        if(freespot == -1)
            return false;
        
        int index= freespot;
        freespot= next[index];
        next[index]= -1;

        if(front[no] == -1) {
            front[no]= index;
        } else {
            next[rear[no]]= index;
        }

        rear[no]= index;
        arr[index]= value;
        return true;
    }
    int dequeue(int no) {
        no--;
        if(front[no] == -1) {
            return -1;
        }

        int index= front[no];
        front[no]= next[index];

        next[index]= freespot;
        freespot= index;

        return arr[index];
    }
};