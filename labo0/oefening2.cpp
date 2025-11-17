#include <iostream>
#include <iomanip>   // voor setw

using namespace std;

int main() {
    cout << setw(4) << "Oct"
         << setw(4) << "Dec"
         << setw(4) << "Hex" << endl;

    for (int i = 0; i <= 64; i++) {
        cout << setw(4) << oct << i      // octale voorstelling
             << setw(4) << dec << i      // decimale voorstelling
             << setw(4) << hex << i      // hexadecimale voorstelling
             << endl;

        // Na gebruik van oct/hex blijft de stream in die modus staan.
        // Daarom telkens opnieuw dec zetten wanneer nodig.
    }

    return 0;
}
