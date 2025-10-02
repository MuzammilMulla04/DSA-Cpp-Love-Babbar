#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &str) {
    int n= str.length();

    stack<char> stack;
    for(char ch: str) {
        switch(ch) {
            case '(':
                stack.push('(');
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                ch= !stack.empty()? stack.top(): '0';
                if(ch == '(')
                    stack.push(ch);
                    break;
            case ')':
                ch= stack.top();
                if(ch == '(')
                    return true;

                stack.pop();
                if(!stack.empty())
                    stack.pop();
                break;
        }
    }

    return false;
}
