//
// Created by Jarno Willems on 03/12/2025.
//

#include <vector>
using namespace std;

template <typename T>
class doos {
private:
    int n;
    vector<T> b;
    unique_ptr<string> * d;
    doos * c;
public:
    doos(const int n = 0, vector<T> b = {}, unique_ptr<string> * d = nullptr, doos * c = nullptr) : n(n), b(b), d(d), c(c) {}
};
