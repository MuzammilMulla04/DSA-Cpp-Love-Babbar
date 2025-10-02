#include<iostream>
#include<string>
using namespace std;

char maximumOccurringCharacter(string str) {
    int count[26]= { 0 };
    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            count[str[i]-'a']++;
        else
            count[str[i]-'A']++;
    }
    int maxIndex=-1;
    for(int i=0, maxCharacter=0; i<26; i++) {
        if(maxCharacter < count[i]) {
            maxIndex= i;
            maxCharacter= count[i];
        }
    }
    return maxIndex +'a';
}

int main() {
    system("cls");

    string sentence;
    cout << "Enter String: ";
    getline(cin, sentence, '\n');

    cout << "Maximum occuring character in \'" << sentence << "\' is : " << maximumOccurringCharacter(sentence);

    cout << endl;
    return 0;
}