/*
 *oef op klasse templates: klasse container bevat naarm (string)
 *en een set met elementen van onbepaald type
 *shcrijf constructur en operatoren +=, * en << voor klasse
 */

#include <iostream>
#include <set>
#include <utility>
#include "containers.h"
using namespace std;

template <typename T> class container;
template <typename T> ostream& operator<<(ostream &out, const container<T> &c);
template <typename T> container<T> operator*(const container<T> &c1, const container<T> &c2);
template <typename T> container<T>& operator+=(container<T> &c, T u);

template <typename T>
class container {
private:
    set<T> elementen;
    string naam;
public:
    container(const T * v, int n,string s): elementen(v, v + n), naam(std::move(s)) {}
    container(const set<T> &v, string s): elementen(v), naam(std::move(s)){}

    friend ostream& operator<< <T>(ostream &out, const container<T> &c);
    friend container<T> operator* <T>(const container<T> &c1, const container<T> &c2);
    friend container<T>& operator+= <T>(container<T> &c, T u);
};

template <typename T>
ostream& operator<<(ostream &out, const container<T> &c) {
    out << "***" << c.naam << "***\n";
    out << "{ ";
    bool first = true;
    for (const auto& elem : c.elementen) {
        if (!first) out << ", ";
        out << elem;
        first = false;
    }
    out << " }\n";
    return out;
}

template <typename T>
container<T>& operator+=(container<T> &c, T u) {
    c.elementen.insert(u);
    return c;
}

template <typename T>
container<T> operator*(const container<T> &c1, const container<T> &c2) {
    set<T> doorsnede_set;

    // Gebruik set_intersection om de doorsnede te berekenen
    std::set_intersection(
        c1.elementen.begin(), c1.elementen.end(),
        c2.elementen.begin(), c2.elementen.end(),
        std::inserter(doorsnede_set, doorsnede_set.begin())
    );
    container<T> c(doorsnede_set, "*** set doorsnede " + c1.naam + " en " + c2.naam + " ***");
    return c;
}

int main() {
    char v[] = {'a','b','e','d', 'c', 'e'};

    container<char> verz1(v,6,"groot");
    //voegt de 6 eerste elementen van v toe aan het attribuut elementen; naam = "groot"

    container<char> verz2(v,2,"klein");
    //voegt de 2 eerste elementen van v toe aan het attribuut elementen; naam = "klein"

    (verz2 += 'z') += 'e'; //voegt (eventueel) een element toe aan elementen

    container<char> doorsnede = verz1*verz2;
    //maak de doorsnede (zie output hieronder voor de naam)

    cout << verz1; //print de naam en de elementen (zie output hieronder)
    cout << verz2;
    cout << doorsnede;
    return 0;
}
