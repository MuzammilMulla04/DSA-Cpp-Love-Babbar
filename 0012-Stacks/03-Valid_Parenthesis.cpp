#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParenthesis(string str) {
    stack<char> s;

    for (auto bracket : str) {
        switch (bracket) {
            case '(':
            case '[':
            case '{':
                s.push(bracket);
                break;
            case ')':
                if (s.empty())
                    return false;
                if (s.top() == '(')
                    s.pop();
                else
                    return false;
                break;
            case ']':
                if (s.empty())
                    return false;
                if (s.top() == '[')
                    s.pop();
                else
                    return false;
                break;
            case '}':
                if (s.empty())
                    return false;
                if (s.top() == '{')
                    s.pop();
                else
                    return false;
                break;
        }
    }

    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

