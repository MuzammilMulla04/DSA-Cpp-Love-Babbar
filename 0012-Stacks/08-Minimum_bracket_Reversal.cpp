#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
    int n = str.length();
// Empty String
    if (n == 0) {
        return 0;
    }

    stack<char> brackets;
    int cost= 0;
    for(int i=0; i<n; i++) {
        switch(str[i]) {
            case '{':
                brackets.push('{');
                break;
            case '}':
                if(brackets.empty()) {
                    brackets.push('{');
                    cost++;
                    break;
                }

                if(brackets.top() != '{') {
                    cost++;
                }

                brackets.pop();
                break;
        }
    }

//Valid & Can become valid
    if(brackets.empty())
        return cost;
//Half Valid
    else if(~brackets.size() & 1) {
        while(!brackets.empty()) {
            switch(brackets.top()) {
                case '}':
                    brackets.pop();
                    if(brackets.top() == '}') {
                        brackets.pop();
                        cost++;
                    }
                    break;
                case '{':
                    brackets.pop();
                   if(brackets.top() == '{') {
                        brackets.pop();
                        cost++;
                    }
                    break;
            }
        }

        return cost;
    }
//Not Valid
    else
        return -1;
}
int findMinimumCostBabbar(string str) {
    int n = str.length();
// Empty String
    if (n == 0) {
        return 0;
    }
// Odd Length
    if(n&1) {
        return -1;
    }
// Remove Valid Brackets
    stack<char> brackets;
    for(int i=0; i<n; i++) {
        switch(str[i]) {
            case '{':
                brackets.push('{');
                break;
            case '}':
                if(!brackets.empty() && brackets.top() == '{')
                    brackets.pop();
                else
                    brackets.push('}');
                break;
        }
    }
// Find Cost
    int openBrackets= 0, closedBrackets= 0;
    while(!brackets.empty()) {
        if(brackets.top() == '{') {
            openBrackets++;
        } else {
            closedBrackets++;
        }
        brackets.pop();
    }

    return (openBrackets+1)/2 + (closedBrackets+1)/2;
}
