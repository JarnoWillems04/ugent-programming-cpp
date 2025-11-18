#include <iostream>
using namespace std;

string genereer_string(int len);
void vul_array_met_strings(string[], int n, int len);
void schrijf(string tab[], int n);
void bepaal_min_max(string tab[], int n, string & min, string & max);
void splits_woorden(const string& zin, string tab[], int n, int & aantal);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int len;
    cin >> len;
    while (len < 5 || len > 15) {
        cout << "Fout" << endl;
        cin >> len;
    }

    string tab[10];
    vul_array_met_strings(tab, 10, len);
    schrijf(tab, 10);

    string min;
    string max;
    bepaal_min_max(tab, 10, min, max);
    cout << "Min: " << min << endl << "Max: " << max << endl;

    cout << "----------" << endl;

    string zin;
    int aantal;

    while (getchar() != '\n');
    cout << "Geef een zin: ";
    getline(cin, zin);
    tab->clear();
    splits_woorden(zin, tab, 10, aantal);
    schrijf(tab, 10);
}

string genereer_string(int len) {
    string s;
    for (int i = 0; i < len; i++) {
        int n = rand()%26;
        s += ('a' + n);
    }
    return s;
}

void vul_array_met_strings(string tab[], int n, int len) {
    for (int i = 0; i < n; i++) {
        tab[i] = genereer_string(len);
    }
}

void schrijf(string tab[], int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << endl;
    }
}


void bepaal_min_max(string tab[], int n, string &min, string &max) {
    min = tab[0];
    max = tab[0];

    for (int i = 1; i < n; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
        else if (tab[i] > max) {
            max = tab[i];
        }
    }
}

void splits_woorden(const string& zin, string tab[], int n, int &aantal) {
    aantal = 0;
    size_t start = 0;

    while (aantal < n) {
        size_t pos = zin.find(' ', start);

        if (pos == string::npos) {
            // laatste woord
            if (start < zin.length()) {
                tab[aantal++] = zin.substr(start);
            }
            break;
        }

        // woord tussen start en pos
        if (pos > start) {
            tab[aantal++] = zin.substr(start, pos - start);

            if (aantal == n) break;
        }

        start = pos + 1;
    }
}


//b) Gebruik c++ arrays zoals in c
//c) min max zijn uitvoersparameters => gebruik geen raw pointers, maar de c++ stijl
     //hoe worden strings vergeleken
//d) controleer input!!
//e) gebruik lidfuncties uit de klasse string
