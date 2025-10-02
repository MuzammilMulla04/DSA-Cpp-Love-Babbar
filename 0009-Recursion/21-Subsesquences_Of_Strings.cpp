#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    if(index >= str.length()) {
        ans.push_back(output);
        return ;
    }

//Exclude
    solve(str, output, index+1, ans);

//Include
    solve(str, output+str[index], index+1, ans);
}
vector<string> subsequences(string str) {
    int index=0;
    string output;
    vector<string> ans;
    solve(str, output, index, ans);
    return ans;
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    cin >> str;

    vector<string> ans= subsequences(str);
    for(auto i: ans)
        cout << i << endl;
//Order of ans is order of Recursion!!
    cout << endl;
    return 0;
}