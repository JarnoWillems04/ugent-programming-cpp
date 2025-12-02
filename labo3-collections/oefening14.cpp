#include <unordered_set>

#include "containers.h"

int main(int argc, char *argv[]) {

    map<char, unordered_set<string>> m;

    string s;
    cin >> s;
    while (s != "STOP") {
        while (getchar() != '\n');
        cin.clear();
        m[s[0]].insert(s);
        cin >> s;
    }

    cout << "Welke char wil je zien?" << endl;
    char c;
    cin >> c;
    cout << "Er zijn " << m[c].size() << " strings ingelezen voor " << c << endl;
    cout << m[c];
}
