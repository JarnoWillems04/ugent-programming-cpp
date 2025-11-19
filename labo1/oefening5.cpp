/*
 *templates
 * geef geen functie mee
 *test ook met struct
 */

#include <iostream>
using namespace std;

struct persoon {
    string naam;
    int leeftijd;
    int lengte; //cm
};

template<typename T>
T grootste(T[], int len);
double grootte(double n);
int grootte(string s);
int grootte(persoon & p);
void initaliseer(persoon &,string, int, int);
void print(const persoon & p);

int main(int argc, char *argv[]) {
    double getallen[5] = {5.5,7.7,2.2,9.9,9.8};
    string woorden[3] = {"geloof","hoop","de liefde"};
    cout << "Grootste getal is: " <<  grootste(getallen,5) << endl;
    cout << "Het grootste woord is: " << grootste(woorden,3) << "." << endl;

    persoon personen[3];
    initaliseer(personen[0], "Samuel", 12, 152);
    initaliseer(personen[1], "Jente", 22, 181);
    initaliseer(personen[2], "Idris", 42, 173);

    cout << "Oudste persoon is: " << endl;
    print(grootste(personen, 3));
}

template<typename T>
T grootste(T tab[], int len) {
    T t = tab[0];
    for (int i = 1; i < len; i++) {
        if (grootte(t) < grootte(tab[i])) {
            t = tab[i];
        }
    }
    return t;
}

double grootte(double n) {
    return n;
}

int grootte(const string s) {
    return s.length();
}

int grootte(persoon &p) {
    return p.leeftijd;
}


void initaliseer(persoon & p,const string naam, int leeftijd, int lengte) {
    p.naam = naam;
    p.leeftijd = leeftijd;
    p.lengte = lengte;
}

void print(const persoon & p) {
    cout << p.naam << ", leeftijd: " << p.leeftijd << ", lengte: " << p.lengte << "cm" << endl;
}

