#include <iostream>
#include <vector>
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

/*************** gekleurde rechthoek ***************/

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

/*************** vierkant ***************/

class vierkant : public rechthoek {
public:
    vierkant(int z = 1) : rechthoek(z, z) {}
    void print(ostream &out);
};

void vierkant::print(ostream & out) {
    out << "Vierkant: " << "zijde: " << hoogte << endl ;
}

/*************** main ***************/

int main() {
    rechthoek r2(4,6);
    gekleurde_rechthoek gr1;
    gekleurde_rechthoek gr3(6,9,"rood");
    vierkant v2(10);

    vector<rechthoek> v;
    v.push_back(r2);
    v.push_back(gr1);
    v.push_back(gr3);
    v.push_back(v2);

    for (int i=0 ; i < v.size() ; i++) {
        cout << v[i];
        cout << "  oppervlakte: " << v[i].oppervlakte() << endl
             << "  omtrek: " << v[i].omtrek() << endl;
    }
    return 0;
}