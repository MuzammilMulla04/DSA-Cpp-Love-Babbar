#include <bits/stdc++.h>
using namespace std;

class Polynomial {
public:
    int* degCoeff;  // Name of your array (Don't change this)
    int size;
    // Constructors
    Polynomial() : size(0), degCoeff(nullptr) {}
    Polynomial(int size) : size(size) {
        degCoeff = new int[size]();
    }
    Polynomial(const Polynomial& p) : size(p.size) {
        degCoeff = new int[size];
        for (int i = 0; i < size; i++)
            degCoeff[i] = p.degCoeff[i];
    }
    // Destructors
    ~Polynomial() {
        delete[] degCoeff;
    }
    // Functions
    void setCoefficient(int degree, int coeff) {
        if (degree >= size) {
            int newSize = degree + 1;
            int* newCoeff = new int[newSize]();

            for (int i = 0; i < size; i++)
                newCoeff[i] = degCoeff[i];

            delete[] degCoeff;
            degCoeff = newCoeff;
            size = newSize;
        }
        degCoeff[degree] = coeff;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            if (degCoeff[i])
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
    // Overloads
    Polynomial operator=(const Polynomial& p2) {
        if (this == &p2)
            return *this;

        delete[] degCoeff;

        size = p2.size;
        degCoeff = new int[size];

        for (int i = 0; i < size; i++)
            degCoeff[i] = p2.degCoeff[i];

        return *this;
    }
    Polynomial operator+(const Polynomial& p2) const {
        int newSize = max(size, p2.size);
        Polynomial p3(newSize);

        for (int i = 0; i < newSize; i++) {
            p3.degCoeff[i] = (i < size ? degCoeff[i] : 0) + (i < p2.size ? p2.degCoeff[i] : 0);
        }

        return p3;
    }
    Polynomial operator-(const Polynomial& p2) const {
        int newSize = max(size, p2.size);
        Polynomial p3(newSize);

        for (int i = 0; i < newSize; i++) {
            p3.degCoeff[i] = (i < size ? degCoeff[i] : 0) - (i < p2.size ? p2.degCoeff[i] : 0);
        }

        return p3;
    }
    Polynomial operator*(const Polynomial& p2) const {
        int newSize = 2 * max(size, p2.size);
        Polynomial p3(newSize);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < p2.size; j++) {
                p3.degCoeff[i + j] += degCoeff[i] * p2.degCoeff[j];
            }
        }

        return p3;
    }
};

int main() {
    system("cls");
    int count1, count2, choice;

    cin >> count1;
    int* degree1 = new int[count1];
    int* coeff1 = new int[count1];
    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }
    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }
    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;
    int* degree2 = new int[count2];
    int* coeff2 = new int[count2];
    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }
    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }
    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;
    Polynomial result;
    switch (choice) {
        case 1:  // Add
            result = first + second;
            result.print();
            break;
        case 2:  // Subtract
            result = first - second;
            result.print();
            break;
        case 3:  // Multiply
            result = first * second;
            result.print();
            break;
        case 4: {  // Copy constructor
            Polynomial third(first);
            if (third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            } else {
                cout << "true" << endl;
            }
            break;
        }
        case 5: {  // Copy assignment operator
            Polynomial fourth(first);
            if (fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            } else {
                cout << "true" << endl;
            }
            break;
        }
    }

    return 0;
}