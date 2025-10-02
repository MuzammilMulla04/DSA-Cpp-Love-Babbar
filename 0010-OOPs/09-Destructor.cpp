#include <bits/stdc++.h>
using namespace std;

class hero {
private:
    int health;
    char level;
public:
    string name;
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
//Destructor
    ~hero() {
        cout << "Destructor Called!" << endl;
    }
};

int main() {
    system("cls");

    hero h1;                    //Static- Constructor & Destructor are called automatically
    hero *h2= new hero();       //Dynamic- Calling constructor manually

    delete h2;                  //Dynamic- Calling detructor manually

    system("pause>0");
    cout << endl;
    return 0;
}