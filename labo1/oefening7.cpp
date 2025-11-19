/*
 *
 */
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream inv1;
    ifstream inv2;
    inv1.open("../labo1/stationnetje.txt");
    inv2.open("../labo1/paddestoel.txt");

    if (inv1.fail()) {
        cout << "Openen van bestand paddenstoel.txt mislukt";
        return 1;
    }
    if (inv2.fail()) {
        cout << "Openen van bestand stationnetje.txt mislukt";
        return 1;
    }
    string s1;
    string s2;
    int i = 1;
    while (getline(inv1, s1) && getline(inv2, s2)) {
        if (!s1.empty() && s1.back() == '\r') {
            s1.pop_back();
        }
        if (!s2.empty() && s2.back() == '\r') {
            s2.pop_back();
        }
        cout << ( i%2 == 0 ? s1 : s2 ) << endl;
        i++;
    }
    inv1.close();
    inv2.close();
}
