#include <iostream>
#include "figuren.h"
#include <memory>
#include <ranges>
#include <sstream>

using namespace std;

class blokkendoos : vector<unique_ptr<figuur>> {
private:
    unique_ptr<figuur> max_opp;
    void schrijf(ostream&) const;

public:
    blokkendoos(const string &);
    unique_ptr<figuur> geef_figuur_met_grootste_oppervlakte();
    void push_back(unique_ptr<figuur> &&);

    friend ostream& operator<<(ostream& out, const blokkendoos& l) {
        l.schrijf(out);
        return out;
    }
};

blokkendoos::blokkendoos(const string & file) {
    ifstream in;
    in.open(file);
    if (in.fail()) {
        return;
    }
    string s;
    while (std::getline(in, s)) {
        std::istringstream iss(s);

        std::string type;
        double o1 = 0, o2 = 0;

        iss >> type >> o1;
        iss >> o2;

        if (type == "cirkel") {
            cirkel c(o1);
            push_back(make_unique<cirkel>(c));
        } else if (type == "vierkant") {
            vierkant v(o1);
            push_back(make_unique<vierkant>(v));
        } else if (type == "rechthoek") {
            rechthoek r(o1, o2);
            push_back(make_unique<rechthoek>(r));
        }
    }
}


void blokkendoos::push_back(unique_ptr<figuur> && f) {
    if (max_opp == nullptr) {
        max_opp = std::move(f);
    } else {
        vector::push_back(std::move(f));

        size_t lastIndex = size() - 1;
        if (max_opp->oppervlakte() < (*this)[lastIndex]->oppervlakte()) {
            std::swap(max_opp, (*this)[lastIndex]);
        }
    }
}

void blokkendoos::schrijf(ostream & out) const {
    for (int i = 0; i < size(); i++) {
        out << *(*this)[i] << endl;
    }
    out << "grootste figuurt: " << endl << *(*this).max_opp << endl;
}

unique_ptr<figuur> blokkendoos::geef_figuur_met_grootste_oppervlakte() {
    int index = 0;
    for (int i = 1; i < size(); i++) {
        if ((*this)[i]->oppervlakte() > (*this)[index]->oppervlakte()) {
            index = i;
        }
    }

    operator[](index).swap(operator[](size()-1));
    // nu staat tweede grootste achteraan; die moet naar max_opp verhuizen
    unique_ptr<figuur> hulpptr = std::move(max_opp);
    max_opp.swap((*this)[size()-1]);
    resize(size()-1);
    return std::move(hulpptr);
}


int main() {
    blokkendoos bd("../labo6-exception-handling-afsluiter/tekstbestanden/figuren.txt");
    cout << endl << "ALLE FIGUREN: " << endl;
    cout << bd << endl;

    cout << endl << "DE 3 GROOTSTE, van groot naar klein: " << endl;
    for (int i=0 ; i<3 ; i++)
        cout << "figuur met grootste opp:    "
             << *bd.geef_figuur_met_grootste_oppervlakte() << endl;

    cout << endl << "DE NIEUWE BLOKKENDOOS BEVAT ALLEEN NOG DE KLEINERE FIGUREN: " << endl;
    cout << bd << endl;
    return 0;
}