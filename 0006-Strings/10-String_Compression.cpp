#include <iostream>
#include <vector>
using namespace std;

int compress(string chars) {
    int i=0, n=chars.length();
    int ansIndex=0;

    while(i<n) {
        int j=i+1;
        while(j<n && chars[i] == chars[j])
            j++;
        chars[ansIndex++]= chars[i];
        int count= j-i;
        if(count>1) {
            string ofCount= to_string(count);
            for(char ch:ofCount)
                chars[ansIndex++]= ch;
        }
        i=j;
    }
    return ansIndex;
}

int main() {
    system("cls");

    string str;
    cout << "Enter String: ";
    cin >> str;

    cout << "Size of String before compression: " << str.length() << endl;
    int l = compress(str);
    cout << "Size of String after compression: " << l << endl;

    cout << endl;
    return 0;
}