#include <iostream>
using namespace std;

class A {
public:
   A();
   A(int, int *);
   A(const A &);
   ~A();
   void print() const;
   A& operator=(const A &);

private:
   int grA;
   int *tA;
};

A& A::operator=(const A &a) {
    if (this != &a) {
        delete[] tA;
        grA = a.grA;
        if (grA > 0) {
            tA = new int[grA];
            for (int i = 0; i < grA; i++) 
                tA[i] = a.tA[i];
        }
    }
    return *this;
}

class B : public A {
public:
   B();
   B(int iA, int *pA, int iB, int *pB);
   B(const B &);
   ~B();
   void print() const;
   B& operator=(const B &);

private:
   int grB;
   int *tB;
};

B& B::operator=(const B &b) {
    if (this != &b) {
        A::operator=(b);
        delete[] tB;
        grB = b.grB;
        if (grB > 0) {
            tB = new int[grB];
            for (int i = 0; i < grB; i++) 
                tB[i] = b.tB[i];
        }
    }
    return *this;
}

int main() {
   int pA[4] = {12, 7, 16, 11};
   int pB[5] = {2, 8, 3, 5, 9};
   A a(4, pA);
   cout << "a.print();" << endl;
   a.print();
   B b1(4, pA, 5, pB);
   cout << "b1.print();" << endl;
   b1.print();
   B b2 = b1;
   cout << "B b2 = b1;\n";
   cout << "b2.print();" << endl;
   b2.print();
   b1 = b1;
   cout << "b1 = b1;\n";
   cout << "b1.print();" << endl;
   b1.print();

   return 0;
}

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

B::B(int iA, int *pA, int iB, int *pB) : A(iA, pA), grB(iB), tB(nullptr) {
    if (grB > 0) {
        tB = new int[grB];
        for (int i = 0; i < grB; i++)
            tB[i] = pB[i];
    }
}

B::B() : B(0, nullptr, 0, nullptr) {}
B::B(const B &b) : A(b), grB(b.grB), tB(nullptr) {
    if (grB > 0) {
        tB = new int[grB];
        for (int i = 0; i < grB; i++)
            tB[i] = b.tB[i];
    }
}

B::~B() {
    cout << "destructor B" << endl;
    delete[] tB;
}

void B::print() const {
    A::print();
    for (int i = 0; i < grB; i++)
        cout << tB[i] << "  ";
    cout << endl;
}
