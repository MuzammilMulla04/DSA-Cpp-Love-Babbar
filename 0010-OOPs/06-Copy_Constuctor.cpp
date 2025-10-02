#include <bits/stdc++.h>
using namespace std;

class hero {
private:
    int health;
    char level;
public:
    string name;
//Copy Constructor
    hero(hero& temp) {
        this->name= temp.name;          //Passing by reference to avoid the infinite loop...
        this->health= temp.health;
        this->level= temp.level;
    }
//Parameterized Constructor
    hero(string name, int health, char level) {
        this->name= name;
        this->health= health;
        this->level= level;
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

    hero h("Muzammil", 100, 'A');
    h.print();

    hero s(h);      //Calling Default Copy Constructor, COMMENT EXPLICIT IMPLEMENTATION!
    s.print();

 
    cout << endl;
    return 0;
}