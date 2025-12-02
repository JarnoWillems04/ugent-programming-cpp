// vbDynamicBinding.cpp
// idem als vbPolymorfisme,
// maar methode print in klasse persoon is nu virtual

// methode print is nu ok
// <<operator werkt nog niet goed
// (kan niet virtual gemaakt worden want is geen lidfunctie)

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class persoon {
 private:
   string naam;

 public:
   persoon(const string & = "?");
   virtual void print() const;  //ENKEL DIT is aangepast!!!!!
 friend ostream& operator<<(ostream &, const persoon &);
}; // persoon

class student : public persoon {
 private:
   string klascode;

 public:
   student(const string & = "?", const string & = "?");
   void print() const;
 friend ostream& operator<<(ostream &, const student &);
}; // student

class leerkracht : public persoon {
 private:
   string vakgroep;

 public:
   leerkracht(const string &nm = "?", const string &vg = "?");
   void print() const;
 friend ostream& operator<<(ostream &, const leerkracht &);
}; // leerkracht

persoon::persoon(const string &nm) : naam(nm) {}

void persoon::print() const {
    cout << naam << " ";
}

ostream& operator<<(ostream &os, const persoon &p) {
    os << "<< uit persoon: ";
    os << p.naam;
    return os;
}

student::student(const string &nm, const string &kl) : persoon(nm), klascode(kl) {}

void student::print() const {
    persoon::print();
    cout << "zit in klas " << klascode << endl;
}


//HEEL BELANGRIJK VOOR NAAM UIT PERSOON TE HALEN
ostream& operator<<(ostream &os, const student &st) {
    os << "<< uit Student: ";
    os << persoon(st) << " zit in klas " << st.klascode;
    return os;
}

leerkracht::leerkracht(const string &nm, const string &vg) : persoon(nm), vakgroep(vg) {}

void leerkracht::print() const {
    persoon::print();
    cout << "uit vakgroep " << vakgroep << endl;
}

ostream& operator<<(ostream &os, const leerkracht &l) {
    os << "<< uit leerkracht: ";
    os << persoon(l) << " uit vakgroep " << l.vakgroep;
    return os;
}

int main() {
    persoon p("Leo");
    p.print();
    cout << endl << p << endl << endl;

    student s("Jan", "1Ba3");
    s.print();
    cout << s << endl << endl;

    leerkracht l("Marc", "EA20");
    l.print();
    cout << l << endl;

    cout << "\np = l;" << endl;
    p = l;
    p.print();
    cout << p << endl;

    // fout:
    // s = p;
    // s = (student)p;

    cout << "\npersoon &rp = s;" << endl;
    persoon &rp = s;
    rp.print();
    cout << rp << endl;

    cout << "\npersoon *pp = &l;" << endl;
    persoon *pp = &l;
    (*pp).print();
    cout << *pp << endl;

    cout << "\nunique_ptr<persoon> up = make_unique<student>(\"An\",\"Ma\");" << endl;
    unique_ptr<persoon> up = make_unique<student>("An", "Ma");
    up->print();
    cout << *up << endl;

    return 0;
}
