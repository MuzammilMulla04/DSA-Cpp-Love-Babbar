#include<stack>
using namespace std;

class SpecialStack {
    stack<int> s;
    int minElement;
public:
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            minElement= data;
            return;
        }

        if(data < minElement) {
            s.push(2*data - minElement);
            minElement= data;
        } else {
            s.push(data);
        }
    }
    void pop() {
        if(s.empty()) {
            return;
        }

        int curr= s.top();
        if(curr < minElement) {
            minElement= 2*minElement - curr;
        }
        s.pop();
    }
    int top() {
        if(s.empty()) {
            return -1;
        }

        int curr= s.top();
        return (curr < minElement)? minElement: curr;        
    }
    int getMin() {
        if(s.empty()) {
            return -1;
        }

        return minElement;
    }
};