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
    virtual void print(ostream &) const;
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
    void print(ostream & out) const override;
};

void gekleurde_rechthoek::print(ostream & out) const{
    rechthoek::print(out);
    out << "  kleur: " << kleur << endl;
}

/*************** vierkant ***************/

class vierkant : public rechthoek {
public:
    vierkant(int z = 1) : rechthoek(z, z) {}
    void print(ostream &out) const override;
};

void vierkant::print(ostream & out) const {
    out << "Vierkant: " << "zijde: " << hoogte << endl ;
}

/*************** main ***************/

int main() {
    vector<unique_ptr<rechthoek>> v;

    v.push_back(make_unique<rechthoek>(4, 6));
    v.push_back(make_unique<gekleurde_rechthoek>());
    v.push_back(make_unique<gekleurde_rechthoek>(6, 9, "rood"));
    v.push_back(make_unique<vierkant>(10));
    for (int i=0 ; i < v.size() ; i++) {
        cout << *v[i];
        cout << "  oppervlakte: " << v[i]->oppervlakte() << endl
             << "  omtrek: " << v[i]->omtrek() << endl;
    }
    return 0;
}