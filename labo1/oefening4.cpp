#include <iostream>

std::string genereer_string(int len);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    std::cout << genereer_string(10);
}

std::string genereer_string(int len) {
    std::string s;

    for (int i = 0; i < len; i++) {
        int n = rand()%26;
        s += ('a' + n);
    }

    return s;
}

