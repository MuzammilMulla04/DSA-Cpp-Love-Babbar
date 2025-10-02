#include<iostream>
#include<map>
using namespace std;

int main() {
    system("cls");

    map<int, string> m;

    m[1]= "Apple";
    m[2]= "Banana";
    m[6]= "Citrus";
    m[3]= "Mango";
    m[5]= "Papaya";
    m[7]= "Melon";
    m[4]= "Chickoo";
    m.insert({8, "Plum"});

    for(auto i:m)
        cout << i.first << ". " << i.second << endl;
    cout << endl;

    cout << "3 is present? : " << m.count(3) << endl;
    cout << endl;

    m.erase(4);
    m.erase(7);

    cout << endl << "after erasing 4 and 7: " << endl;
    for(auto i:m)
        cout << i.first << ". " << i.second << endl;
    cout << endl;

    auto itr= m.find(2);
    cout << "find(2): " << itr->second << endl;
    for(auto i=itr; i != m.end(); i++)
        cout << (*i).first << ". " << i->second << endl;
    cout << endl;

    cout << endl;
    return 0;
}