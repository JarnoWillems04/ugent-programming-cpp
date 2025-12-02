#include <iostream>
#include <map>
#include <set>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
    int lengte; //cm
};

template<typename T>
void print(const vector<T> &);

ostream& operator<<(ostream &out, const persoon &p) {
    out << p.naam << " (" << p.leeftijd << " jaar, " << p.lengte  << "cm)";
    return out;
}

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (const T& i : v) {
        out << i << " ";
    }
    return out;
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
    for (const auto& [key, value] : m) {
        out << key << " -> " << value << endl;
    }
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T> & s) {
    for (const auto& elem : s) {
        out << "\"" << elem << "\", ";
    }
    return out;
}

// // Set uitschrijven? als je komma's tussen de elementen wil
// // (en geen komma meer na het laatste element),
// // kan je geen gebruik maken van een for-each-lus.
// // Er moet dus met een iterator gewerkt worden!
// template<typename T>
// ostream& operator<<(ostream &out, const set<T> &s) {
//     if (s.size() == 0)
//         out << "{ }";
//     else {
//         out << "{ ";
//         typename set<T>::const_iterator it = s.begin();
//         for (int i=0 ; i<s.size()-1 ; i++)
//             out << *it++ << " , ";
//         out << *it << " }";
//     }
//     out << endl;
//     return out;
// }


int main() {

    // Vector van personen
    vector<persoon> mensen = {
        {"Samuel", 12, 152},
        {"Jente", 22, 181},
        {"Idris", 42, 173}
    };
    cout << "Vector<persoon>: " << mensen << endl;

    // Vector van vector<int>
    vector<vector<int>> vv;
    vv.push_back({5});
    cout << "Vector<vector<int>>: " << vv << endl;

    // Map testen
    map<string, int> scores = {
        {"Jan", 10},
        {"Piet", 15},
        {"Klaas", 20}
    };
    cout << "Map<string,int>: " << scores << endl;

    // Set testen
    set<int> s = {5, 2, 8, 3};
    cout << "Set<int>: " << s << endl;

    return 0;
}

template<typename T>
void print(const vector<T> & v) {
    for (const T& i : v) {
        cout << i << " ";
    }
}
