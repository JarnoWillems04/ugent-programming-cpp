//
// Created by Jarno Willems on 03/12/2025.
//
#include "doos.cpp"

template <typename T>
class schijf {
private:
    doos<T> * _doos;
public:
    schijf(doos<T> * d = nullptr) : _doos(d) {}
};