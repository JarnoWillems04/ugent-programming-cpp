//
// Created by Jarno Willems on 26/11/2025.
//

#ifndef LABO_CPP_CONTAINERS_H
#define LABO_CPP_CONTAINERS_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v);

template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m);

template<typename T>
ostream& operator<<(ostream& out, const unordered_set<T> & s);

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (const T& i : v) {
        out << i << " ";
    }
    return out;
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
    for (const auto& [key, value] : m) {
        out << key << " -> " << value << endl;
    }
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const unordered_set<T> & s) {
    for (const auto& elem : s) {
        out << "\"" << elem << "\", ";
    }
    return out;
}

#endif //LABO_CPP_CONTAINERS_H