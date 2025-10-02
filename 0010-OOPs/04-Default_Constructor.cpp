#include <bits/stdc++.h>
using namespace std;

class hero {
private:
    int health;
    char level;
    void read(string Name, int Health, char Level) {
        name= Name;
        health= Health;
        level= Level;
    }
public:
    string name;
//Default Constructor
    hero() {
        string Name;
        int Health;
        char Level;
        
        cout << "Enter name: ";
        cin >> Name;
        cout << "Enter Health: ";
        cin >> Health;
        cout << "Enter Level: ";
        cin >> Level;

        read(Name, Health, Level);
    }
// Getters & Setters
    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }
    void setHealth(int Health) {
        health= Health;
    }
    void setLevel(char Level) {
        level= Level;
    }
// Other Functions
    void print() {
        cout << endl;    
        cout << "Name: " << name << endl;
        cout << "Health: " << getHealth() << endl;
        cout << "Level: " << getLevel() << endl;
        cout << endl;    
    }
};

int main() {
    system("cls");

    hero h;
    h.print();

    cout << endl;
    return 0;
}