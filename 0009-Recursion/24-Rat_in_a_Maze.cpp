#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<vector<int>>& m, int n, int x, int y, string output, vector<string>& ans) {
    if(m[x][y] == 0)
        return ;
    if(x == n-1 && y == n-1) {
        ans.push_back(output);
        return ;
    }
//DOWN
    if(x+1 < n && m[x+1][y] == 1) {
        m[x][y]= 0;
        solve(m, n, x+1, y, output+"D", ans);
        m[x][y]= 1;
    }
//RIGHT
    if(y+1 < n && m[x][y+1] == 1) {
        m[x][y]= 0;
        solve(m, n, x, y+1, output+"R", ans);
        m[x][y]= 1;
    }
//UP
    if(x-1 >= 0 && m[x-1][y] == 1) {
        m[x][y]= 0;
        solve(m, n, x-1, y, output+"U", ans);
        m[x][y]= 1;
    }
//LEFT
    if(y-1 >= 0 && m[x][y-1] == 1) {
        m[x][y]= 0;
        solve(m, n, x, y-1, output+"L", ans);
        m[x][y]= 1;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    int x=0, y=0;
    string output= "";
    vector<string> ans;
    solve(m, n, x, y, output, ans);
    return ans;
}

int main() {
    system("cls");

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> m;

    cout << "Enter Elements:-" << endl;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        m.push_back(temp);
    }

    vector<string> ans= findPath(m, n);
    if(ans.size() == 0)
        cout << "NO" << endl;
    else {
        for(auto i: ans)
            cout << i << endl;
        cout << "YES" << endl;
    }
 
    cout << endl;
    return 0;
}