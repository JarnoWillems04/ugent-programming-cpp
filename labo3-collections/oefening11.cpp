
#include <iostream>
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

int main() {
    vector<persoon> mensen = {
        {"Samuel", 12, 152},
        {"Jente", 22, 181},
        {"Idris", 42, 173}
    };

    cout << mensen << endl;

    // laatste deel van de opdracht:
    vector<vector<int>> vv;
    vv.push_back({ 5 });   // één vector met één int

    cout << vv << endl;    // moet nu werken

    return 0;
}

template<typename T>
void print(const vector<T> & v) {
    for (const T& i : v) {
        cout << i << " ";
    }
}
