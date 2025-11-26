#include "containers.h"

int main(int argc, char *argv[]) {
    const int aantal = 5;
    vector<string> v[aantal];
    v[1] = {"aap", "noot", "mies"};

    for (const auto & i  : v) {
        cout << i << endl;
    }

    vector<vector<int>> vv(aantal);

    for (int i = 0; i < vv.capacity(); i++) {
        vv.at(i).reserve(i+1);

        for (int j = 0; j < vv.at(i).capacity(); j++) {
            vv.at(i).push_back(10*j + 10);
        }
    }

    for (int i = vv.size() - 1; i >= 0 ; i--) {
        for (int j = vv.at(i).size() - 1; j >= 0; j--) {
            cout << vv.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
