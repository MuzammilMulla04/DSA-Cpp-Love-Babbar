#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    //creation
    unordered_map<string, int> m;

    //insertion
    //1
    pair<string, int> p= make_pair("Apple", 5);
    m.insert(p);

    //2
    pair<string, int> q("Mango", 2);
    m.insert(q);

    //3
    m["banana"]= 3;      // creates key and assigns value to it

    //what if..?
    m["banana"]= 8;      // Updates value of created key

    //Accessing
    cout << "Accessing" << endl;
    cout << m["Apple"] << endl;
    cout << m.at("Mango") << endl;

    cout << "Creating/Assigning" << endl;
    //cout << m.at("Mango") << endl;     //gives error as no key
    cout << m["Mango"] << endl;          //creates a key with '0' value
    cout << m.at("Mango") << endl;       //now it wont give errors

    //size of map
    cout << "Size" << endl;
    cout << m.size() << endl;

    //check key presence
    cout << "key presence" << endl;
    cout << m.count("Apple") << endl;    //true then returns 1
    cout << m.count("Plum") << endl;         //false then returns 0

    //erase
    cout << "erase" << endl;
    m.erase("Mango");
    cout << m.size() << endl;

    //Iteration using auto
    cout << "Iteration using auto" << endl;
    for(auto i:m)
        cout << i.first << " -> " << i.second << endl;

    //Iteration using iterators
    cout << "Iteration using iterators" << endl;
    unordered_map<string, int> :: iterator it= m.begin();
    while(it != m.end()) {
        cout << it->first << " -> " << it->second << endl;
        it++;
    }

/* 
    Note: In unordered map, key are re-arranged in ascending order
    Try using 'map' instead of 'unorder_map' in lines 9 & 57
    And see output in order of their insertion

    Time Complexity-
    map -- O(log(n))
    unordered map -- O(1)

*/ 

    return 0;
}