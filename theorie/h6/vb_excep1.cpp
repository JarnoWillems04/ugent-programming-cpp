#include <iostream>
#include <string>
using namespace std;

int fac(int getal) {
    if (getal < 0) {
        throw "exceptie: negatief getal";
        //welke catch bij onderstaande throw?
        //throw "exceptie: " + to_string(getal) + " is een negatief getal";
    }

    int res = 1;
    for (int i = 2; i <= getal; i++)
        res *= i;
    return res;
}

int main() {
    int getal;
    cout << "getal: ";
    cin >> getal;
    try {
        cout << getal << "! = "
             << fac(getal) << endl;
        cout << "einde1" << endl;
    }
    catch (const char *s) { // const niet vergeten!!!
        cout << s << endl;
    }
    // uitbreiden naar meerdere catch'en is uiteraard mogelijk
    // eerst meest specifieke handlers schrijven!!
    cout << "einde2" << endl;
    return 0;
}
