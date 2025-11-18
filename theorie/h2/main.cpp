#include <iostream>
using namespace std;

template<typename T>
void kleinste_eerst(unique_ptr<T> &, unique_ptr<T> &);

int main(int argc, char *argv[]) {

    unique_ptr<int> pi1 = make_unique<int>(8);
    unique_ptr<int> pi2 = make_unique<int>(24);
    unique_ptr<string> ps1 = make_unique<string>("peer");
    unique_ptr<string> ps2 = make_unique<string>("banaan");
    kleinste_eerst(pi1, pi2);
    kleinste_eerst(ps1, ps2);
    cout << *pi1 << "   " << *ps1;
}

template<typename T>
void kleinste_eerst(unique_ptr<T> &p1, unique_ptr<T> &p2) {
    if (*p1 > *p2) {
        p2.swap(p1);
    }
}
