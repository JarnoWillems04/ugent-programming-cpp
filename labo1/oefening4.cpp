#include <iostream>
using namespace std;

string genereer_string(int len);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    cout << genereer_string(10);
}

string genereer_string(int len) {
    string s;

    for (int i = 0; i < len; i++) {
        int n = rand()%26;
        s += ('a' + n);
    }

    return s;
}

