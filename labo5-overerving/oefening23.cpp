// Wordt wss niet op examen gemaakt, gewoon handig
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
protected: //protected zodat lid functie van vierkant hier aan kan
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
protected:
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

/*************** gekleurd_vierkant ***************/

class gekleurd_vierkant : public gekleurde_rechthoek, public vierkant {
public:
    gekleurd_vierkant(int z = 1,const string & kleur = "onbekend")
        : gekleurde_rechthoek(z, z, kleur), vierkant(z) {}
    void print(ostream &out) const override;
    // voorzie geen extra attributen!
    // overschrijf geen lidfuncties indien dit niet nodig is!
};

void gekleurd_vierkant::print(ostream &out) const {
    vierkant::print(out);
    out << "  kleur: " << kleur << endl;
}


//aangezien rechthoek een "ambiguous base" is van gekleurd_vierkant
ostream& operator<<(ostream& out, const gekleurd_vierkant& v) {
    v.print(out);
    return out;
}

/*************** main ***************/

int main() {
    gekleurd_vierkant gv1;
    cout << gv1;
    cout << "  oppervlakte: " << gv1.vierkant::oppervlakte() << endl
         << "  omtrek: " << gv1.vierkant::oppervlakte() << endl;

    gekleurd_vierkant gv2(12);
    gv2.print(cout);
    cout << "  oppervlakte: " << gv2.vierkant::oppervlakte() << endl
         << "  omtrek: " << gv2.vierkant::omtrek() << endl;

    gekleurd_vierkant gv3(15,"geel");
    cout << gv3;
    cout << "  oppervlakte: " << gv3.vierkant::oppervlakte() << endl
         << "  omtrek: " << gv3.vierkant::omtrek() << endl;
    return 0;
}