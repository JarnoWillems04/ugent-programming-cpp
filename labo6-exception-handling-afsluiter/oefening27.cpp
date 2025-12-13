#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class bestand_niet_lang_genoeg : public logic_error {
public:
    bestand_niet_lang_genoeg(const string &message):
        logic_error(message) {}
};

string regel_uit_bestand(const string &naam, int nr);

int main() {
    vector<string> bestandsnamen{
        "niks","een","twee","drie","vier",
                     "vijf","zes","zeven","acht","negen","tien","elf","twaalf"
    };
    vector<int> nrs{8,5, 2, 10, 7, 3, 8, 4, 1, 1, 6, 2, 4};

    string bestanden_niet_gevonden;
    string bestanden_niet_lang_genoeg;
    string eerste_woorden;

    for (int i = 0; i < bestandsnamen.size(); i++) {
        try {
            cout << regel_uit_bestand(bestandsnamen[i] + ".txt", nrs[i]) << endl;
        } catch (runtime_error&) {
            bestanden_niet_gevonden += bestandsnamen[i] + " ";
        } catch (const string& s) {
            eerste_woorden += s + " ";
        } catch (bestand_niet_lang_genoeg&) {
            bestanden_niet_lang_genoeg += bestandsnamen[i] + " ";
        }
    }

    cout << endl << endl << "BESTANDEN NIET GEVONDEN:" << endl;
    cout << bestanden_niet_gevonden;

    cout << endl << "BESTANDEN NIET LANG GENOEG:" << endl;
    cout << bestanden_niet_lang_genoeg << endl;

    cout << endl << "BESTANDEN ZONDER STARTWOORD 'VERHAAL':" << endl;
    cout << "dit waren de woorden die er wel als eerste stonden:" << endl << endl;
    cout << eerste_woorden << endl << endl;
    return 0;
}

string regel_uit_bestand(const string &naam, int nr) {
    ifstream inv;
    inv.open("../labo6-exception-handling-afsluiter/tekstbestanden/" + naam);

    if (inv.fail()) {
        throw runtime_error(naam + " kan niet geopend worden.");
    }
    string s;
    int i = 0;
    getline(inv, s);
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }
    if (s != "VERHAAL") {
        throw string(s);
    }
    while (i<nr && getline(inv,s))
        i++;
    if (inv.fail())
        throw bestand_niet_lang_genoeg(
            naam + " heeft geen " + to_string(nr) + " regels.");
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }
    inv.close();
    return s;
}
