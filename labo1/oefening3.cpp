#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    char ch1 = 'x';
    string s1 = "" + ch1; //Hier wordt eigenlijk een pointer verschoven
    cout << "karakter " <<  ch1  << " omgezet: " <<  s1 << "." << endl;

    char ch2 = 'y';
    string s2;
    s2 += ch2; // Hier wordt er aan overloading gedaan en weet hij wat er moet gebeuren
    cout << "karakter " <<  ch2  << " omgezet: " <<  s2 << "." << endl;
}
