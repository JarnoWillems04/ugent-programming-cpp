/*
 *a) lidfunctie van break
 *b) externe functie
 *c) friend functie breuk
 *niet alles is nodig, vb geen copy constructor
 */

#include <iostream>
#include <set>
#include "breuk.cpp"
using namespace std;

void deel1() {
    breuk a(2,5);
    breuk b(1,-2);
    cout << a << " + " << b << " = ";
    cout << (a+b) << " [-1/10 ?]" << endl;
    cout << "De tegengestelde breuk van " << a << " is " << -a << " [-2/5 ?]." << endl;

    breuk f = a + b;
    cout << "De som van " << a << " en " << b << " is " << f << " [-1/10 ?]" << endl;
    breuk g(f);
    cout << "en dat is gelijk aan de breuk " << g  << " [-1/10 ?]." << endl;

    cout << a << " - " << b << " = ";
    cout << (a-b) << " [9/10 ?]" << endl;
    cout << a << " += " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a += b;
    cout << a << " [-1/10 ?]" << endl;
    cout << a << " -= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a -= b;
    cout << a << " [2/5 ?]" << endl;

    cout << "Ik verhoog nu de breuk a=" << a  << " met 2 eenheden; dan is a=";
    cout << ++(++a) << " [12/5 ?]" << endl;

    cout << "Na dit uitschrijven zal b=" << b++  << " ook met een eenheid verhoogd zijn, nl. ";
    cout << "b=" << b << " [1/2 ?]" << endl;

    breuk c(2,3);
    breuk d(3,4);
    breuk e(1,2);
    (c -= d) += e;
    cout << "Indien hier 5/12 staat, heb je de operatoren -= en += goed geschreven: " << c << endl;
}


void deel2() {
    breuk d(2,10);
    breuk e(3);

    cout << d << " is stambreuk: " << is_stambreuk(d) << endl;

    breuk f(3,4);
    cout << endl << "We starten van een breuk, en tellen er telkens een eenheid bij op: " << endl << endl;
    for (int i=0; i<10; i++) {
        cout  << i << " meer dan " <<  f << " is " << (i+f) << " = " << (f+i) << endl;
    }

    cout << endl << "Al deze breuken in een verzameling: " << endl;
    set<breuk> verz;
    for (int i=0; i<10; i++) {
        verz.insert(i+f);
        verz.insert(f+i);
    }
    for (const breuk &b : verz){
        cout << b << endl;
    }
}

void deel3() {
    breuk a(13,12);
    breuk b(2);
    breuk c;
    cout << endl << "Geef c op (onder de vorm teller noemer): ";
    cin >> c;
    if (a == c)
        cout << a << " is gelijk aan " << c  << endl;
    if (a != c)
        cout << a << " is niet gelijk aan " << c  << endl;
}

int main() {
    deel1();
    deel2();
    deel3();
    return 0;
}