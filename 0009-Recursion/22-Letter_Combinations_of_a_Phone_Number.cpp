#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string digits, string map[], string output, int index, vector<string>& ans) {
    if(index >= digits.length()) {
        ans.push_back(output);
        return ;
    }

    int number= digits[index] - '0';
    string value= map[number];

    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, map, output, index+1, ans);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0)
        return ans;
    string map[10]= { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    int index=0;
    string output;
    solve(digits, map, output, index, ans);
    return ans;
}

int main() {
    system("cls");

    string digits;
    cout << "Enter String: ";
    cin >> digits;

    vector<string> ans= letterCombinations(digits);
    for(auto i: ans)
        cout << i  << endl;
 
    cout << endl;
    return 0;
}