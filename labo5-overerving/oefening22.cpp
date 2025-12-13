#include <memory>
#include <vector>
#include <iostream>
using namespace std;

class lange_slang : vector<unique_ptr<int> > {
private:
    void schrijf(ostream &) const;

public:
    void vul(const vector<int> &);

    lange_slang &concatenate(lange_slang &);

    friend ostream &operator<<(ostream &out, const lange_slang &l) {
        l.schrijf(out);
        return out;
    }
};

void lange_slang::schrijf(ostream &out) const {
    for (int i = 0; i < (*this).size(); i++) {
        if ((*this)[i] != nullptr) {
            out << *((*this)[i]) << " ";
        }
    }
}


void lange_slang::vul(const vector<int> &v) {
    (*this).resize(v.size());
    for (int i = 0; i < v.size(); i++) {
        (*this)[i] = make_unique<int>(v[i]);
    }
}

lange_slang &lange_slang::concatenate(lange_slang &ls) {
    int l = (*this).size();
    (*this).resize(l + ls.size());
    for (int i = l; i < (*this).size(); i++) {
        if (&ls == (this)) {
            (*this)[i] = make_unique<int>(*ls[i - l]);
        } else {
            (*this)[i] = std::move(ls[i - l]);
        }
    }
    return (*this);
}


int main() {
    lange_slang a, b, c;
    a.vul({1, 2}); // via a vind je de getallen 1 en 2
    b.vul({3, 4, 5}); // via b vind je de getallen 3, 4 en 5
    c.vul({6, 7}); // via c vind je de getallen 6 en 7
    cout << "a: " << a << endl; //output= a: 1 2
    cout << "b: " << b << endl; //output= b: 3 4 5
    cout << "c: " << c << endl << endl; //output= c: 6 7

    a.concatenate(a);
    // via a vind je nu de 4 getallen 1, 2, 1 en 2
    cout << "na a.concatenate(a)" << endl;
    cout << "a: " << a << endl; // output= a: 1 2 1 2

    a.concatenate(b).concatenate(c);
    // via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
    // b en c zijn leeg
    cout << "na a.concatenate(b).concatenate(c)" << endl;
    cout << "a: " << a << endl; //output= a: 1 2 1 2 3 4 5 6 7
    cout << "b: " << b << endl; //output= b:
    cout << "c: " << c << endl; //output= c:
    return 0;
}
