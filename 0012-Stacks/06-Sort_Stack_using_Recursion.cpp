#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int>& stack) {
    if(stack.empty()) {
        cout << endl;
        return;
    }

    int temp= stack.top();
    cout << temp << " ";

    stack.pop();
    printStack(stack);
    stack.push(temp);
}

void sortedInsert(stack<int>& stack, int element) {
    if(stack.empty() || element >= stack.top()) {
        stack.push(element);
        return;
    }
    if(element < stack.top()) {
        int temp= stack.top();
        stack.pop();
        sortedInsert(stack, element);
        stack.push(temp);
    }
}
void sortStack(stack<int> &stack) {
	if(stack.empty()) {
        return;
    }
    
    int temp= stack.top();
    stack.pop();

    sortStack(stack);
    sortedInsert(stack, temp);
}

int main() {
    system("cls");

    int n;
    cout << "Enter Size: ";
    cin >> n;

    stack<int> stack;
    cout << "Enter Elements: ";
    while(n--) {
        int value;
        cin >> value; 

        stack.push(value);
    }

    cout << "Before Sorting: ";
    printStack(stack);

    sortStack(stack);

    cout << "After Sorting: ";
    printStack(stack);

    return 0;
}