//
// Created by Jarno Willems on 26/11/2025.
//

#ifndef LABO_CPP_CONTAINERS_H
#define LABO_CPP_CONTAINERS_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (const T& i : v) {
        out << i << " ";
    }
    return out;
}

#endif //LABO_CPP_CONTAINERS_H