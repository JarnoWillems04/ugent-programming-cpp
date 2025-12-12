#include <iostream>
#include <vector>
#include "containers.h" //zodat we vectoren kunnen uitschrijven m.b.v. operator<<
using namespace std;

template<typename T>
class mijn_vector : public vector<T> { //zonder die public kan je niet aan de public elementen van vetor
private:
public:
    void verdubbel(bool dubbel = false);
    friend ostream& operator<<(ostream &, const mijn_vector &);
};

int main() {
    mijn_vector<int> v{10,20,30};
    cout << v;
    v.verdubbel();
    cout << "na verdubbelen zonder parameter: " << v;
    v.verdubbel(true);
    cout << "na verdubbelen met param true: " << v;

    mijn_vector<int> w(v);
    cout << "een kopie van v: " << w;

    mijn_vector<double> u(7);
    cout << "een vector met 7 default-elt: " << u;
    for (int i=0; i < u.size(); i++)
        u[i] = i*1.1;
    cout << "na opvullen met getallen: " << u;
    u.verdubbel();
    cout << "na verdubbelen zonder parameter: " << u;

    return 0;
}