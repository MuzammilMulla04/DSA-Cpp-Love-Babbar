#include <bits/stdc++.h>
using namespace std;

// My Approach
char firstNonRepeatingCharacter(string str) {
    unordered_map<char, int> freq;
    for (char& letter : str)
        freq[letter]++;

    for (char& letter : str) {
        cout << letter << "-> " << freq[letter] << endl;
        if (freq[letter] == 1)
            return letter;
    }

    return str[0];
}

// Best Soln on CodingNinjas
char firstNonRepeatingCharacter(string str) {
    int n = str.size();
    vector<int> hash(255, 0);

    for (int i = 0; i < n; i++)
        hash[str[i]]++;

    for (int i = 0; i < 255; i++) {
        if (hash[str[i]] == 1)
            return str[i];
    }

    return str[0];
}

int main() {
    system("cls");

    int T;
    cin >> T;

    vector<string> str;
    while (T--) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    for (string& s : str)
        cout << firstNonRepeatingCharacter(s) << endl;

    return 0;
}