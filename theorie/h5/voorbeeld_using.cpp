#include <iostream>
using namespace std;

class A {
public:
  A(int = -1, int = -2);
  int getVarA1() const;
  int getVarA2() const;

private:
  int varA1, varA2;
};

class B : public A {
public:
  using A::A;
  //  wat indien je onderstaande constructor toevoegt en using in commentaar zet?
  //B(int vB) : varB(vB) {}
  // wat indien je beiden voorziet (using + constructor)?
  int getVarB() const;
  // wat als A geen default constructor heeft met/zonder using (haal =-1 weg)?
private:
  int varB;
};

int main() {
    B b0;
    cout << "B b0;" << endl;
    cout << "  varA1: " << b0.getVarA1() << endl
         << "  varA2: " << b0.getVarA2() << endl
         << "  varB: " << b0.getVarB() << endl;

    B b1(4);
    cout << "B b1(4);" << endl;
    cout << "  varA1: " << b1.getVarA1() << endl
         << "  varA2: " << b1.getVarA2() << endl
         << "  varB: " << b1.getVarB() << endl;

    B b2(5, 6);
    cout << "B b2(5,6);" << endl;
    cout << "  varA1: " << b2.getVarA1() << endl
         << "  varA2: " << b2.getVarA2() << endl
         << "  varB: " << b2.getVarB() << endl;

    B b3(b1);
    cout << "B b3(b1);" << endl;
    cout << "  varA1: " << b3.getVarA1() << endl
         << "  varA2: " << b3.getVarA2() << endl
         << "  varB: " << b3.getVarB() << endl;
    return 0;
}

A::A(int vA1, int vA2) : varA1(vA1), varA2(vA2) {}

int A::getVarA1() const {
  return varA1;
}

int A::getVarA2() const {
  return varA2;
}

int B::getVarB() const {
  return varB;
}
