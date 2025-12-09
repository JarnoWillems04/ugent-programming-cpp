#include <iostream>
using namespace std;

class rechthoek {
public:
     rechthoek() : hoogte(1), breedte(1) {}
     rechthoek(int hoogte, int breedte) : hoogte(hoogte), breedte(breedte) {}
     // rechthoek(int hoogte = 1, int breedte = 1) : hoogte(hoogte), breedte(breedte) {}
     int omtrek() const;
     int oppervlakte() const;
     void print(ostream &) const;
     friend ostream& operator<<(ostream &, const rechthoek &);
protected:
     int hoogte;
     int breedte;
};

int rechthoek::omtrek() const {
     return 2*hoogte + 2*breedte;
}

int rechthoek::oppervlakte() const {
     return hoogte*breedte;
}

void rechthoek::print(ostream & out) const {
     out << "Rechthoek: " << hoogte << " op " << breedte << endl ;
}

ostream& operator<<(ostream &uit, const rechthoek &b) {
     b.print(uit);
     return uit;
}


class gekleurde_rechthoek : public rechthoek {
private:
     string kleur;
public:
     gekleurde_rechthoek(int hoogte = 1, int breedte = 1, const string & kleur = "onbekend")
          : rechthoek(hoogte, breedte), kleur(kleur) {}
     void print(ostream & out);
};

void gekleurde_rechthoek::print(ostream & out) {
     rechthoek::print(out);
     out << "  kleur: " << kleur << endl;
}

class vierkant : public rechthoek {
public:
    vierkant(int z = 1) : rechthoek(z, z) {}
    void print(ostream &out);
};

void vierkant::print(ostream & out) {
     out << "Vierkant: " << "zijde: " << hoogte << endl ;
}


int main () {
    rechthoek r1;
    r1.print(cout);
    cout << "  oppervlakte: " << r1.oppervlakte() << endl
         << "  omtrek: " << r1.omtrek() << endl;

    rechthoek r2(4,6);
    cout << r2;
    cout << "  oppervlakte: " << r2.oppervlakte() << endl
         << "  omtrek: " << r2.omtrek() << endl;

    gekleurde_rechthoek gr1;
    gr1.print(cout);
    cout << "  oppervlakte: " << gr1.oppervlakte() << endl
         << "  omtrek: " << gr1.omtrek() << endl;

    gekleurde_rechthoek gr2(5,7);
    cout << gr2;
    cout << "  oppervlakte: " << gr2.oppervlakte() << endl
         << "  omtrek: " << gr2.omtrek() << endl;

    gekleurde_rechthoek gr3(6,9,"rood");
    gr3.print(cout);
    cout << "  oppervlakte: " << gr3.oppervlakte() << endl
         << "  omtrek: " << gr3.omtrek() << endl;

    vierkant v1;
    cout << v1;
    cout << "  oppervlakte: " << v1.oppervlakte() << endl
         << "  omtrek: " << v1.omtrek() << endl;

    vierkant v2(10);
    v2.print(cout);
    cout << "  oppervlakte: " << v2.oppervlakte() << endl
         << "  omtrek: " << v2.omtrek() << endl;

    return 0;
}