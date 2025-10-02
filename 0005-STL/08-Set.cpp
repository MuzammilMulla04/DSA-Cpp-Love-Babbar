#include<iostream>
#include<set>
using namespace std;

int main() {
    system("cls");

    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(4);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(1);
    s.insert(6);

    for(int i:s)
        cout << i << " ";
    cout << endl;

    set<int>::iterator it= s.begin();
    it++;
    it++;
    s.erase(it);
    for(int i:s)
        cout << i << " ";
    cout << endl;

    cout << "3 is present? : " << s.count(3) << endl;
    cout << "5 is present? : " << s.count(5) << endl;

    set<int>::iterator itr= s.find(5);
    cout << "Value present in itr: " << *itr << endl;

    for(auto it=s.find(4); it != s.end(); it++)
        cout << *it << " ";

    cout << endl;
    return 0;
}
