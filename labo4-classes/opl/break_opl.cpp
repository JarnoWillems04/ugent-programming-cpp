// zet onderstaande code in een apart bestand breuk.cpp
#include <iostream>
#include <cmath>
using namespace std;

int mijn_ggd(int a, int b){
    if(a < 0 || b < 0)
        return mijn_ggd(abs(a),abs(b));
    if(b == 0)
        return a;
    return mijn_ggd(b,a%b);
}

class breuk {
  private:
    int teller, noemer;
    void normaliseer();

  public:
    // constructor voor DEEL 1, 2 en 3
    breuk(int =0 , int =1);

    // voor DEEL 1:
    breuk operator+(const breuk&) const;
    breuk operator-(const breuk&) const;
    breuk operator-() const;
    breuk& operator+=(const breuk&);
    breuk& operator-=(const breuk&);
    breuk& operator++();
    breuk operator++(int);
    // merk op: operator= en copyconstructor moet je niet schrijven
    //    want die bestaan al (en hun standaardwerking volstaat:
    //    er zijn immers geen raw pointers als attributen)

    // operator<< is geen lidfunctie;
    friend ostream& operator<<(ostream &, const breuk &);

    // voor DEEL 2
    breuk operator+(int) const;
    bool operator<(const breuk&) const; //om breuken te kunnen toevoegen aan een set
    friend bool is_stambreuk(const breuk&);

    // voor DEEL 3
    bool operator==(const breuk&) const;
    bool operator!=(const breuk&) const;
    friend istream& operator>>(istream&, breuk&);
};

//***************** DEEL 1 ********************
//private lidfunctie
void breuk::normaliseer() {
    if (noemer < 0) {
        noemer *= -1; teller *= -1;
    }
    int deler = mijn_ggd(teller,noemer);
    teller /= deler;
    noemer /= deler;
}

//constructor
breuk:: breuk(int t, int n) : teller(t),noemer(n) {
    normaliseer();
}

//extern (friend van breuk)
ostream& operator<<(ostream &uit, const breuk &b) {
    uit << b.teller ;
    if (b.noemer != 1) uit << "/" << b.noemer;
    return uit;
}

breuk breuk::operator+(const breuk &b) const {
    return breuk(b.noemer*teller + noemer*b.teller, noemer*b.noemer);
}

breuk breuk::operator-(const breuk &b) const {
    return breuk(b.noemer*teller - noemer*b.teller, noemer*b.noemer);
}

breuk breuk::operator-() const {
    return breuk(-teller,noemer);
}

breuk& breuk::operator+=(const breuk &b) {
    teller = b.noemer*teller + noemer*b.teller;
    noemer = noemer*b.noemer;
    normaliseer();
    // of gebruik makend van +: *this = *this + b;
    return *this;
}

breuk& breuk::operator-=(const breuk &b) {
    operator+=(-b);
    return *this;
}

breuk& breuk::operator++() {
    teller += noemer;
    normaliseer();
    return *this;
}

breuk breuk::operator++(int a) {
    breuk temp(*this);
    teller += noemer;
    normaliseer();
    return temp;
}


//***************** DEEL 2 ********************
//externe friend functie
bool is_stambreuk(const breuk &a) {
    return a.teller == 1;
}

breuk breuk::operator+(int x) const {
    breuk hulp(x);
    return *this+hulp;
}

//externe functie (ook niet friend)!!
breuk operator+(int x, const breuk &b) {
    return b+x;
}

//zodat breuken kunnen toegevoegd worden aan een set
bool breuk::operator<(const breuk &b) const {
    return teller*b.noemer < noemer*b.teller;
}


//***************** DEEL 3 ********************
bool breuk::operator==(const breuk& b) const {
    return teller == b.teller && noemer == b.noemer;
}

bool breuk::operator!=(const breuk & b) const {
    return !operator==(b);
}

istream& operator>>(istream &in,  breuk &b) {
    in >> b.teller >> b.noemer;
    b.normaliseer();
    return in;
}
// einde bestand breuk.cpp