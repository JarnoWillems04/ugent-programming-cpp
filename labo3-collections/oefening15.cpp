#include "containers.h"

//Zorg net zoals andere funcites, eerst declaren dan implementeren in containers.h
//Anders errors

void print_woorden(const string &zoek, const vector<map<char,unordered_set<string> > > &v) {
    if (zoek.size() < v.size()) {
        //geen [ ] gebruiken op de map wegens const &!!
        map<char,unordered_set<string> >::const_iterator it;
        it = v[zoek.size()].find(zoek[0]);
        if (it != v[zoek.size()].end())
            cout << it->second;
        else
            cout << "geen woorden van lengte " << zoek.size() << " met startletter " << zoek[0] << endl;
    } else
        cout << "geen woorden van lengte " << zoek.size() << endl;
}

int main() {
    vector<map<char,unordered_set<string> > > v(10); // start bij lengte 10
    string woord;
    cout << "geef woorden, eindig met STOP" << endl;
    cin >> woord;
    while (woord != "STOP") {
        if (woord.size() > v.size()-1)
            v.resize(woord.size() + 1);
        v[woord.size()][woord[0]].insert(woord);
        cin >> woord;
    }
    cout << v;
    print_woorden("test",v);
    print_woorden("Sinterklaas",v);
    return 0;
}

