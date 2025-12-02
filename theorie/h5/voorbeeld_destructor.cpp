#include <iostream>
using namespace std;

class A {
public:
   A();
   A(int, int *); //deep copy: new gebruiken in constructor
   A(const A &); //deep copy maken (geen shared raw pointer)
   ~A(); //dus: destructor voorzien
   void print() const;
   void wijzigA(int, int);

private:
   int grA;
   int *tA;
};

A::A(int i, int *p) : grA(i), tA(nullptr) {
    if (grA > 0) {
        tA = new int[grA];
        for (int i = 0; i < grA; i++)
            tA[i] = p[i];
    }
}

A::A() : A(0, nullptr) {}
A::A(const A &a) : A(a.grA, a.tA) {}

A::~A() {
    cout << "destructor A" << endl;
    delete[] tA;
}

void A::print() const {
    for (int i = 0; i < grA; i++)
        cout << tA[i] << "  ";
    cout << endl;
}

void A::wijzigA(int index, int nieuw) {
    if (index < grA)
        tA[index] = nieuw;
}

class B : public A {
public:
   B(int iA, int *pA, int iB, int *pB); //new gebruiken in constructor
   B(const B &); //deep copy maken (geen shared raw pointer)
   ~B(); //dus: destructor voorzien
   void print() const;
   void wijzigB(int, int);

private:
   int grB;
   int *tB;
};

B::B(int iA, int *pA, int iB, int *pB) : A(iA, pA), grB(iB), tB(nullptr) {
    if (grB > 0) {
        tB = new int[grB];
        for (int i = 0; i < grB; i++)
            tB[i] = pB[i];
    }
}

//waarom roep ik de vorige constructor niet gewoon op?
B::B(const B &b) : A(b), grB(b.grB), tB(nullptr) {
    if (grB > 0) {
        tB = new int[grB];
        for (int i = 0; i < grB; i++)
            tB[i] = b.tB[i];
   }
}
//opm: indien A(b) niet vermeld wordt,
//wordt de default-constructor van A opgeroepen

B::~B() {
   cout << "destructor B" << endl;
   delete[] tB;
}

void B::print() const {
    A::print();  //aanroep print van de klasse A
    for (int i = 0; i < grB; i++)
        cout << tB[i] << "  ";
    cout << endl;
}

void B::wijzigB(int index, int nieuw) {
    if (index < grB)
       tB[index] = nieuw;
}

int main() {
   int pA[4] = {12, 7, 16, 11};
   int pB[5] = {2, 8, 3, 5, 9};
   A a(4, pA);
   cout << "a.print();" << endl;
   a.print();

   // B b0;
   // er is geen automatische default-constructor
   // aangezien B een andere constructor voorziet

   B b1(4, pA, 5, pB);
   cout << "b1.print();" << endl;
   b1.print();

   B b2(b1);
   cout << "b2.print();" << endl;
   b2.print();
   b2.wijzigA(2, -6);
   b2.wijzigB(4, 0);
   cout << "na b2.wijzigA(2,-6); en b2.wijzigB(4,0);\n";
   cout << "b2.print();" << endl;
   b2.print();
   cout << "b1.print();" << endl;
   b1.print();

   cout << "b2.A::print();" << endl;
   b2.A::print();

   return 0;
}
