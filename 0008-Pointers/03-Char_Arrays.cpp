#include<iostream>
using namespace std;

int main() {
    system("cls");

    int arr[5]= {1, 2, 3, 4, 5};
    char ch[6]= "abcde";

    cout << "arr: " << arr << endl;
    cout << "ch: " << ch << endl;
    cout << endl;

    char *c= &ch[0];
    cout << "c: " << c << endl;     //  Prints entire String
    cout << endl;

    //What if, there's no '\0' in string?
    char temp= 'z';
    char *temp_ptr= &temp;
    cout << "temp: " << temp << endl;
    cout << "temp_ptr: " << temp_ptr << endl;   //  Prints until cout finds another '\0'
    cout << endl;

    //char crt[6]= "abcdf";     YES
    //char *crt= "abcdf";       NO

    cout << endl;
    return 0;
}