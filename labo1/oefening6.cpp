/*
 *default parameters nodig
 *
 */
#include <iostream>
using namespace std;

void schrijf(const int tab[], int n, bool achterstevoren = false, char tussenteken = ' ');

int main(int argc, char *argv[]) {
    const int t[] = {1, 3, 5, 7, 9, 11, 13};
    schrijf(t,7);
    schrijf(t,7,true);
    schrijf(t,7,false,'-');
    schrijf(t,7,true,'-');
}

void schrijf(const int tab[], int n, bool achterstevoren, char tussenteken) {
    cout << (achterstevoren ? tab[n-1] : tab[0]);
    for (int i = achterstevoren ? n-2 : 1; achterstevoren ? i >= 0 : i <  n; achterstevoren ? i-- : i++) {
        cout << tussenteken << tab[i];
    }
    cout << endl;
}