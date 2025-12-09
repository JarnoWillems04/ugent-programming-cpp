#include <iostream>
#include <fstream>
using namespace std;

double gemiddelde(const string &s) {
    ifstream inv(s);
    if (!inv)
        throw "openen bestand " + s + " mislukt";
    int aantal = 0, som = 0, getal;
    while (inv >> getal) {
        aantal++;
        som += getal;
    }
    if (!inv.eof())
        throw "Dit bestand bevat fouten";
    if (aantal == 0)
        throw "Dit bestand is leeg";
    return (som * 1.0) / aantal;
}

int main(int argc, char **argv) {
    if (argc == 1)
        cout << "geen extra strings op commandolijn";
    for (int i = 1; i < argc; i++) {
        try {
            cout << "bestand " << argv[i] << endl;
            double gem = gemiddelde(argv[i]);
            cout << "gemiddelde = " << gem << endl;
        } catch (const char *s) {
            cout << s << endl;
        } catch (const string &s) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
