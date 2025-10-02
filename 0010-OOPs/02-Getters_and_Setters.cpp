#include <bits/stdc++.h>
using namespace std;

class hero {
private:    //Default
    int health;
    char level;
public:
    string name;
// Getters
    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }
// Setters
    void setHealth(int Health) {
        health= Health;
    }
    void setLevel(char Level) {
        level= Level;
    }
};

int main() {
    system("cls");

    hero h;
    h.name= "babbar";
    h.setHealth(100);
    h.setLevel('A');

    cout << "Name: " << h.name << endl;
    cout << "Health: " << h.getHealth() << endl;
    cout << "Level: " << h.getLevel() << endl;

    cout << endl;
    return 0;
}