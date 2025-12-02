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

A& A::operator=(const A &a) {
    delete[] tA;
    grA = a.grA;
    if (grA > 0) {
        tA = new int[grA];
        for (int i = 0; i < grA; i++)
            tA[i] = a.tA[i];
    }
    return *this;
}

int main() {
    int pA1[4] = {12, 7, 16, 11};
    A a1(4, pA1);
    cout << "a1.print();" << endl;
    a1.print();
    int pA2[2] = {18, 15};
    A a2(2, pA2);
    cout << "a2.print();" << endl;
    a2.print();
    a2 = a1;
    cout << "a2 = a1;\n";
    cout << "a2.print();" << endl;
    a2.print();
    a1 = a1;
    cout << "a1 = a1;\n";
    cout << "a1.print();" << endl;
    a1.print();
    return 0;
}
