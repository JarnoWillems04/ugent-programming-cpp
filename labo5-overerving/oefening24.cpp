//EXAMEN

#include <functional>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class persoon {
public:
    string voornaam, naam;
    int leeftijd;
    // merk op: de attributen van persoon zijn public, zodat er
    //      geen getters moeten voorzien worden voor de lambdafuncties
    persoon(const string &v, const string &n, int l)
        : voornaam(v), naam(n), leeftijd(l) {}
};

// hoeft niet friend te zijn, want de attributen van persoon zijn public
ostream& operator<<(ostream &out, const persoon &p) {
    out << p.naam << " " << p.voornaam << " (" << p.leeftijd << ")";
    return out;
}

class groep : public vector<persoon> {
public:
    persoon geef_kleinste(bool (*f)(const persoon &,const persoon &));
    // Hier komt de definitie van de lidfunctie geef_kleinste, die een persoon teruggeeft.
    // Deze lidfunctie krijgt als parameter een logische functie mee
    // die twee objecten van de klasse persoon met elkaar vergelijkt.
    // Deze (parameter)functie geeft een bool terug als resultaat:
    // true indien de eerste parameter "kleiner" is dan de tweede parameter, false indien niet.
};

persoon groep::geef_kleinste(bool (*f)(const persoon &, const persoon &)) {
    int index_kleinste = 0;
    for (int i=1 ; i<size() ; i++) {
        if (f(operator[](i),operator[](index_kleinste)))
            index_kleinste = i;
    }
    return operator[](index_kleinste);
}


int main() {
    groep gr;
    gr.push_back(persoon("Ann","Nelissen",22));
    gr.push_back(persoon("Bert","Mertens",12));
    gr.push_back(persoon("Celle","Lauwers",55));

    cout << "Eerste qua naam:     " << gr.geef_kleinste([] (const persoon & p1,const persoon & p2) -> bool {
        return p1.naam < p2.naam;
    }) << endl;
    cout << "Eerste qua voornaam: " << gr.geef_kleinste([] (const persoon & p1, const persoon & p2) -> bool {
        return p1.voornaam < p2.voornaam;
    }) << endl;
    cout << "Jongste:             " << gr.geef_kleinste([] (const persoon & p1, const persoon & p2) -> bool {
        return p1.leeftijd < p2.leeftijd;
    }) << endl;
    return 0;
}