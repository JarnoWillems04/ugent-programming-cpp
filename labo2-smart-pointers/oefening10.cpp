#include <iostream>
#include <memory>
using namespace std;

template<typename T>
void dupliceer(vector<unique_ptr<T>> &, int);

int main() {
    unique_ptr<string> pnamen[] = {
        make_unique<string>("Rein"),
        make_unique<string>("Ada"), make_unique<string>("Eppo"),
        make_unique<string>("Pascal"), make_unique<string>("Ilse")
    };
    vector<unique_ptr<string> > namenvector;
    namenvector.reserve(size(pnamen));
    for (auto & i : pnamen) {
        namenvector.push_back(std::move(i));
    }
    dupliceer(namenvector, 3);
    for (const auto & i : namenvector) {
        cout << *i << " ";
    }
}

template<typename T>
void dupliceer(vector<unique_ptr<T>> & v, int n) {
    int original = v.size();
    v.reserve(original * n);

    for (int i = 0; i < original; i++) {
        const T& value = *v[i*n];
        auto pos = v.begin() + i * n;
        for (int j = 1; j < n; j++) {
            v.insert(pos, make_unique<T>(value));
        }
    }
}
