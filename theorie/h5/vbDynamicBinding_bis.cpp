// vbDynamicBinding_bis.cpp

// <<-operator werkt nu prima, aangezien deze
// de private/protected virtual methode print aanroept
// Merk op: enkel <<-operator kan nog gebruikt worden
// (want methode print is private/protected geworden)
// <<-operator hoeft enkel voorzien te worden in de klasse persoon
// (methode print is voorzien in alle klassen)

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class persoon {
 private:
   string naam;

 protected:
   virtual void print(ostream &) const;

 public:
   persoon(const string & = "?");
 friend ostream& operator<<(ostream &, const persoon &);
}; // persoon

class student : public persoon {
 private:
   string klascode;
   void print(ostream &) const;

 public:
   student(const string & = "?", const string & = "?");
}; // student

class leerkracht : public persoon {
 private:
   string vakgroep;
   virtual void print(ostream &) const;

 public:
   leerkracht(const string & = "?", const string & = "?");
}; // leerkracht

persoon::persoon(const string &nm) : naam(nm) {}

void persoon::print(ostream &os) const {
   os << naam;
}

ostream& operator<<(ostream &os, const persoon &p) {
   p.print(os);
   return os;
}

student::student(const string &nm, const string &kl) : persoon(nm), klascode(kl) {}

void student::print(ostream &os) const {
   persoon::print(os);
   os << " zit in klas " << klascode;
}

leerkracht::leerkracht(const string &nm, const string &vg) : persoon(nm), vakgroep(vg) {}

void leerkracht::print(ostream &os) const {
   persoon::print(os);
   os << " uit vakgroep " << vakgroep;
}

int main() {
   persoon p("Leo");
   cout << p << endl << endl;

   student s("Jan", "1Ba3");
   cout << s << endl << endl;

   leerkracht l("Marc", "EA20");
   cout << l << endl;

   cout << "\np = l;" << endl;
   p = l;
   cout << p << endl;

   cout << "\npersoon &rp = s;" << endl;
   persoon &rp = s;
   cout << rp << endl;

   cout << "\npersoon *pp = &l;" << endl;
   persoon *pp = &l;
   cout << *pp << endl;

   cout << "\nunique_ptr<persoon> up = make_unique<student>(\"An\",\"Ma\");" << endl;
   unique_ptr<persoon> up = make_unique<student>("An", "Ma");
   cout << *up << endl;

   return 0;
}
