#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

void lees(const string &bestandsnaam, map<char,set<string> > &m) {
    string woord; //geen auto mogelijk: geen initialisatie
    ifstream inv(bestandsnaam);  //geen auto mogelijk: inv wordt niet herkend als ifstream
    while (inv >> woord) {
        cout << woord << endl;
        m[woord[0]].insert(woord);
    }
}

string langstewoord(char letter, const map<char,set<string> > &m) {
    string langste; //geen auto mogelijk: geen initialisatie
    auto it_find = m.find(letter);  //hier is auto toegelaten en zinvol
    if (it_find != m.end()) {
        auto it = it_find->second.begin();  //hier is auto toegelaten en zinvol
        while (it != it_find->second.end()) {
            if (it->size() > langste.size())
                langste = *it;
            it++;
        }
    }
    return langste;
}

int main() {
    map<char,set<string> > m; //geen auto mogelijk: geen initialisatie
    string naam;   //geen auto mogelijk: geen initialisatie
    cout << "Bestandsnaam: ";
    cin >>  naam;
    lees(naam, m);
    char letter = 's';  //auto mogelijk, maar is hier niet zinvol
    cout << "Het langste woord met de letter " << letter << " is: ";
    cout << langstewoord(letter,m);
    return 0;
}