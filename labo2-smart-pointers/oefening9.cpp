#include <memory>
#include <iostream>
using namespace std;

// void schrijf(const string *, int);
void schrijf(const unique_ptr<string> *, int);
void verwijder(unique_ptr<string> *, int, int);

int main() {
    string namen[] = {"Rein","Ada","Eppo","Pascal","Ilse"};
    unique_ptr<string> pnamen[5];

    for (int i = 0; i < 5; i++) {
        pnamen[i] = make_unique<string>(namen[i]);
    }
    schrijf(pnamen,5);
    verwijder(pnamen,5,4);
    schrijf(pnamen,5);
    verwijder(pnamen,5,1);
    schrijf(pnamen,5);
    return 0;
}


// void schrijf(const string *s, int aantal) {
//     cout << endl;
//     for (int i=0; i < aantal-1; i++)
//         cout << s[i] << " - ";
//     cout << s[aantal-1];
// }

void schrijf(const unique_ptr<string> * s, int aantal) {
    cout << endl;
    for (int i = 0; i < aantal-1; i++) {
        if (s[i] != nullptr) {
            cout << *s[i] << " - ";
        } else {
            cout << "NULL - ";
        }
    }
    if (s[aantal -1] != nullptr) {
        cout << *s[aantal - 1];
    } else {
        cout << "NULL";
    }
}

// void verwijder(string *s, int aantal, int volgnr) {
//     for (int i = volgnr; i < aantal-1; i++)
//         s[i] = s[i+1];
//     s[aantal-1] = "";  //laatste element leeg maken
// }

void verwijder(unique_ptr<string> * s, int aantal, int volgnr) {
    for (int i = volgnr; i < aantal-1; i++) {
        s[i] = std::move(s[i + 1]);
    }
    s[aantal-1] = nullptr;
}
