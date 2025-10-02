#include <bits/stdc++.h>
using namespace std;

class hero {
private:
    int health;
public:
    char *name;
    char level;
//Shallow-Copy Constructor
    hero(hero& temp) {
        this->name= temp.name;          //Shallow Copy- Same Memory allocated, of pointer-type data member, to copy Object
        this->health= temp.health;      //Deep Copy- Different Memory allocated to copy Object
        this->level= temp.level;
    }
//Simple Constructor
    hero() {
        name= new char[100];        //Allocating memory dynamically to creation of object
    }
//Parameterized Constructor
    hero(int health, char level) {
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
    void setName(char name[]) {
        strcpy(this->name, name);
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
};

int main() {
    system("cls");

    hero h1;
    h1.setHealth(100);
    h1.setLevel('A');
    char name[]= "Muzammil";
    h1.setName(name);
    h1.print();

    // hero h2(h1);
    hero h2= h1;        //Another Way!
    h2.print();

    h1.name[0]= 'L';
    h1.print();
    h2.print();     //Gets changed too!

    cout << endl;
    return 0;
}