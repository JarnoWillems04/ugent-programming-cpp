// vbPolymorfisme.cpp
// twee klassen afgeleid van klasse persoon
// polymorfisme is oke, dynamic binding niet (ook niet voor <<operator)

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class persoon {
 private:
   string naam;

 public:
   persoon(const string & = "?");
   void print() const;
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
    os << (persoon)l << " uit vakgroep " << l.vakgroep;
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
    cout << endl << p << endl;

    // fout:
    // s = p;
    // s = (student)p;

    cout << "\npersoon &rp = s;" << endl;
    persoon &rp = s;
    rp.print();
    cout << endl << rp << endl;

    cout << "\npersoon *pp = &l;" << endl;
    persoon *pp = &l;
    (*pp).print();
    cout << endl << *pp << endl;

    cout << "\nunique_ptr<persoon> up = make_unique<student>(\"An\",\"Ma\");" << endl;
    unique_ptr<persoon> up = make_unique<student>("An", "Ma");
    up->print();
    cout << endl << *up << endl;

    return 0;
}
