#include <iostream>
#include <set>
#include "../containers.h"
using namespace std;

//declaratie van de klasse container
template <typename T>
class container {
    private:
        set<T> elementen;
        string naam;
    public:
        container() {};
        container(const T[], int, const string &);
        container<T>& operator+=(const T &);
        container<T> operator*(const container<T> &) const;

    /*
    Indien je voor de friend operator<< ook gebruik zou willen maken van de typename T,
    dan moet deze operator inline geimplementeerd worden.
    Aangezien we alle operatoren outline willen implementeren, moet er voor (externe) friend functies
    een andere typename gebruikt worden (hier U).
    Bij de implementatie van deze operator mag wel opnieuw T gebruikt worden (zie verder).
    */
    template<typename U>
    friend ostream& operator<<(ostream &, const container<U> &);
};

//gegeven hoofdprogramma
int main() {
    char v[] = {'a','b','e','d', 'c', 'e'};
    container<char> verz1(v,6,"groot");
    container<char> verz2(v,2,"klein");
    (verz2 += 'z') += 'e';
    container<char> doorsnede = verz1*verz2;
    cout << verz1;
    cout << verz2;
    cout << doorsnede;
    return 0;
}

//verdere uitwerking van de klasse container
template <typename T>
container<T>::container(const T data[], int n, const string &_naam) : naam(_naam) {
    for (int i=0 ; i<n ; i++)
        elementen.insert(data[i]);
}

template <typename T>
container<T>& container<T>::operator+=(const T &c) {
    elementen.insert(c);
    return *this;
}

template <typename T>
container<T> container<T>:: operator*(const container<T> &c) const {
    container<T> vv;
    vv.naam = "doorsnede " + naam + " en " + c.naam;
    for (const T &el : elementen) {
        if (c.elementen.count(el) > 0)
            vv.elementen.insert(el);
    }
    return vv;
}

template <typename T>
ostream& operator<<(ostream &out, const container<T> &c) {
    out << "*** set " << c.naam << " ***\n" << c.elementen;
    return out;
}