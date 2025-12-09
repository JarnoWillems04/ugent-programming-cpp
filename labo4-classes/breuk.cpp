#include <cmath>
#include <iostream>
using namespace std;

class breuk {
public:
    breuk(int t = 1, int n = 1) : teller(t), noemer(n) {}

    friend ostream& operator<<(ostream &out, const breuk &b);
    friend istream& operator>>(istream &in, breuk &b);
    friend breuk operator+(const breuk &b1, const breuk &b2);
    friend breuk operator-(const breuk &b1, const breuk &b2);
    friend breuk& operator+=(breuk &b1, const breuk &b2);
    friend breuk& operator-=(breuk &b1, const breuk &b2);
    friend breuk operator-(const breuk &b1);
    friend breuk operator++(breuk &b1, int i);
    friend breuk& operator++(breuk &b1);
    friend breuk operator+(const breuk &b1, int i);
    friend bool operator==(const breuk &, const breuk &);
    friend bool operator!=(const breuk &, const breuk &);
    friend bool operator<(const breuk &b1, const breuk &b2);
    friend bool is_stambreuk(const breuk &b);
private:
    int teller;
    int noemer;
    void normaliseer();
};

int mijn_ggd(int a, int b) {
    if (a < 0 || b < 0)
        return mijn_ggd(abs(a), abs(b));
    if (b == 0)
        return a;
    return mijn_ggd(b, a % b);
}

void breuk::normaliseer() {
    const int ggd = mijn_ggd(noemer, teller);
    teller = teller/ggd;
    noemer = noemer/ggd;
    if (noemer < 0) {
        teller = -teller;
        noemer = -noemer;
    }
}


ostream& operator<<(ostream &out, const breuk &b) {
    out << "[" << b.teller << "/" << b.noemer << "]";
    return out;
}

istream& operator>>(istream &in, breuk &b) {
    int t;
    int n;
    in >> t;
    in >> n;

    b.teller = t;
    b.noemer = n;

    return in;
}

breuk operator+(const breuk &b1, const breuk &b2) {
    const int n = b1.noemer * b2.noemer;
    const int t = b1.teller * b2.noemer + b2.teller * b1.noemer;

    breuk b(t, n);
    b.normaliseer();
    return b;
}

breuk operator-(const breuk &b1, const breuk &b2) {
    const int n = b1.noemer * b2.noemer;
    const int t = b1.teller * b2.noemer - b2.teller * b1.noemer;

    breuk b(t, n);
    b.normaliseer();
    return b;
}

breuk operator++(breuk &b1, int i) {
    breuk b = b1;
    b1.teller += b1.noemer;
    b1.normaliseer();
    return b;
}

breuk& operator++(breuk &b1) {
    b1.teller = b1.teller + b1.noemer;
    b1.normaliseer();
    return b1;
}

breuk& operator+=(breuk &b1, const breuk &b2) {
    const int n = b1.noemer * b2.noemer;
    const int t = b1.teller * b2.noemer + b2.teller * b1.noemer;
    b1.teller = t;
    b1.noemer = n;
    b1.normaliseer();
    return b1;
}

breuk& operator-=(breuk &b1, const breuk &b2) {
    const int n = b1.noemer * b2.noemer;
    const int t = b1.teller * b2.noemer - b2.teller * b1.noemer;
    b1.teller = t;
    b1.noemer = n;
    b1.normaliseer();
    return b1;
}

breuk operator-(const breuk &b1) {
    breuk b(-b1.teller, b1.noemer);
    b.normaliseer();
    return b;
}

breuk operator+(const breuk &b1, int i) {
    const int teller = b1.teller + i * b1.noemer;
    breuk b(teller, b1.noemer);
    b.normaliseer();
    return b;
}

breuk operator+(int i, const breuk &b1) {
    return b1 + i;
}

bool operator==(const breuk &b1, const breuk &b2) {
    return (b1.teller == b2.teller) && b1.noemer == b2.noemer;
}

bool operator!=(const breuk &b1, const breuk &b2) {
    return !(b1 == b2);
}



bool operator<(const breuk &b1, const breuk &b2) {
    return b1.teller/b1.noemer < b2.teller/b1.noemer;
}

bool is_stambreuk(const breuk &b) {
    return b.noemer == 1;
}



