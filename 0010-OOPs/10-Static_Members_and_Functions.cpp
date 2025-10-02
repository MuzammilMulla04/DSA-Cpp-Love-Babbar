#include <bits/stdc++.h>
using namespace std;

class hero {
private:
    int health;
    char level;
public:
    string name;
    static int timeToComplete;      //Static Members
//Constructor
    hero() {
        cout << "Constructor Called!" << endl;
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
        cout << endl << "[" << name << ", " << getHealth()  << ", " << getLevel() << "]" << endl;
    }
    static void printTimeToComplete() {         //Static Functions- can only access static members
        cout << timeToComplete << endl;
    }
//Destructor
    ~hero() {
        cout << "Destructor Called!" << endl;
    }
};
//Initialization of static member
int hero::timeToComplete= 5;

int main() {
    system("cls");

    cout << hero::timeToComplete << endl;
    
    hero a;
    cout << a.timeToComplete << endl;       //Not Recommended, as it doesn't belong to an object, but the entire class itself!

    cout << "Static Function: ";
    hero::printTimeToComplete();

    cout << endl;
    return 0;
}