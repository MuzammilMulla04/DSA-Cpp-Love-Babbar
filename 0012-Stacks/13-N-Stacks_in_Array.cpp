#include <bits/stdc++.h>
using namespace std;

// SC: O(s+n) ...... Since, O(2*s + n)= O(s+n)

// TC: O(n)
class NStackMine {
    vector<int> top;
    int* arr;
    int noOfStacks, sizeOfArray;

public:
    NStackMine(int noOfStacks, int sizeOfArray) {
        this->noOfStacks = noOfStacks;
        this->sizeOfArray = sizeOfArray;

        top.resize(noOfStacks + 1, -1);
        arr = new int[sizeOfArray];
        // Initialize Array
        for (int i = 0; i < sizeOfArray; i++) {
            arr[i] = 0;
        }
    }
    bool push(int value, int stackNo) {
        if (top[noOfStacks] == sizeOfArray - 1) {
            return false;
        }
        // Shift-Push
        for (int i = sizeOfArray - 1; i > top[stackNo] && i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        // Update Tops
        for (int i = stackNo; i <= noOfStacks; i++) {
            top[i]++;
        }
        // Push Value
        arr[top[stackNo]] = value;
        return true;
    }
    int pop(int stackNo) {
        if (top[stackNo - 1] == top[stackNo]) {
            return -1;
        }
        // Get Value
        int value = arr[top[stackNo]];
        // Shift-Pop
        for (int i = top[stackNo]; i < sizeOfArray - 1; i++) {
            arr[i] = arr[i + 1];
        }
        // Update Tops
        for (int i = stackNo; i <= noOfStacks; i++) {
            top[i]--;
        }
        return value;
    }
};
// TC: O(1)
class NStackBabbar {
    int *arr, *top, *next;
    int n, s, freespot;
public:
    NStackBabbar(int N, int S): n(N), s(S), freespot(0) {
        arr= new int[s];

        top= new int[n];
        for(int i=0; i<n; i++)
            top[i]= -1;

        next= new int[s];
        for(int i=0; i<s; i++) {
            next[i]= i+1;
        }
        next[s-1]= -1;
    }
    bool push(int x, int m) {
        if(freespot == -1) {
            return -1;
        }

        int index= freespot;
        freespot= next[index];
        arr[index]= x;
        next[index]= top[m-1];
        top[m-1]= index;

        return true;
    }
    int pop(int m) {
        if(top[m-1] == -1) {
            return -1;
        }

        int index= top[m-1];
        top[m-1]= next[index];
        int value= arr[index];
        next[index]= freespot;
        freespot= index;

        return value;

    }
};
