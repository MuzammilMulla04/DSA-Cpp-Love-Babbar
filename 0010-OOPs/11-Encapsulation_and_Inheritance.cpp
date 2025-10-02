#include <bits/stdc++.h>
using namespace std;

class human {
public:
    int height;
    int weight;
    int age;
    int getAge() {
        return this->age;
    }
    void setWeight(int weight) {
        this->weight= weight;
    }
    void printHuman() {
        cout << this->height << endl << this->weight << endl << this->age << endl;
    }
};
class male:public human {
public:
    string name;
    void sleep() {
        cout << this->name << " is sleeping!" << endl;
    }
    void printMale() {
        printHuman();
        cout << name << endl;
    }
    void tellAccessModifiers() {
        vector<string> accessModifiers= {"public", "protected", "private"};

        cout << "Base Class" <<  " " << "Inheritance Type" << ": " << "Child Class" << endl;
        cout << accessModifiers[0] <<  " " << accessModifiers[0] << ": " << accessModifiers[0] << endl;
        cout << accessModifiers[0] <<  " " << accessModifiers[1] << ": " << accessModifiers[1] << endl;
        cout << accessModifiers[0] <<  " " << accessModifiers[2] << ": " << accessModifiers[2] << endl;
        cout << accessModifiers[1] <<  " " << accessModifiers[0] << ": " << accessModifiers[1] << endl;
        cout << accessModifiers[1] <<  " " << accessModifiers[1] << ": " << accessModifiers[1] << endl;
        cout << accessModifiers[1] <<  " " << accessModifiers[2] << ": " << accessModifiers[2] << endl;
        cout << accessModifiers[2] <<  " " << accessModifiers[0] << ": " << "Not Accessible" << endl;
        cout << accessModifiers[2] <<  " " << accessModifiers[1] << ": " << "Not Accessible" << endl;
        cout << accessModifiers[2] <<  " " << accessModifiers[2] << ": " << "Not Accessible" << endl;
    }
};


int main() {
    system("cls");

    male m;
    m.printMale();

    m.setWeight(60);
    m.name= "Muzammil";
    m.printMale();

    m.sleep();

    m.tellAccessModifiers();
    
    cout << endl;
    return 0;
}