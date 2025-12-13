#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/************************** declaratie doos *********************************/
template<typename T>
class doos {
public:
    doos();

    doos(const doos<T> &);

    doos<T> &operator=(const doos<T> &);

    virtual ~doos();

    doos(doos<T> &&); //move constructor
    doos<T> &operator=(doos<T> &&); //move operator
private:
    vector<T> b;
    int n;
    doos<T> *c;
    unique_ptr<string> *d;

    void copy(const doos<T> &);
};

/************************** declaratie schijf *********************************/
template<typename T>
class schijf {
public:
    schijf();

    schijf(const schijf<T> &);

    schijf<T> &operator=(const schijf<T> &);

    virtual ~schijf();

    schijf(schijf<T> &&);
    schijf<T> &operator=(schijf<T> &&);
private:
    doos<T> *a;
};

/******************************* schijf *****************************/
template<typename T>
schijf<T>::schijf() : a(nullptr) {
}

template<typename T>
schijf<T>::schijf(const schijf<T> &s) : a(nullptr) {
    if (s.a) {
        //geen nullptr
        a = new doos<T>(*s.a);
    }
}

template<typename T>
schijf<T>::~schijf() {
    delete a;
}

template<typename T>
schijf<T> &schijf<T>::operator=(const schijf<T> &s) {
    if (this != &s) {
        delete a;
        a = nullptr;
        if (s.a) {
            a = new doos<T>(*s.a);
        }
    }
    return *this;
}

template<typename T>
schijf<T>::schijf(schijf<T> && s): a(s.a) {
    s.a = nullptr;
}

template<typename T>
schijf<T> &schijf<T>::operator=(schijf<T> && s) {
    if (this != &s) {
        delete a;
        a = s.a;
        s.a = nullptr;
    }
    return *this;
}


/********************************* doos **************************/
template<typename T>
doos<T>::doos() : n(0), c(nullptr), d(nullptr) {
}

//hulplidfunctie (om duplicated code te vermijden)
template<typename T>
void doos<T>::copy(const doos<T> &ds) {
    b = ds.b; //vector kopieren
    if (ds.c) {
        c = new doos<T>(*ds.c);
    } else
        c = nullptr;
    n = ds.n;
    if (n > 0) {
        d = new unique_ptr<string>[n]; //n elementen in de array
        // de elementen van de array d moeten ingevuld worden.
        for (int i = 0; i < n; i++) {
            if (ds.d[i]) {
                d[i] = make_unique<string>(*ds.d[i]);
            } else
                d[i] = nullptr;
        }
    } else
        d = nullptr;
}

template<typename T>
doos<T>::doos(const doos<T> &ds) {
    copy(ds);
}

template<typename T>
doos<T> &doos<T>::operator=(const doos<T> &ds) {
    if (this != &ds) {
        delete c;
        delete[] d;
        copy(ds);
    }
    return *this;
}

template<typename T>
doos<T>::~doos() {
    delete c;
    delete[] d;
}

template<typename T>
doos<T>::doos(doos<T> && ds): b(move(ds.b)), n(ds.n), c(ds.c), d(ds.d) {
    ds.c = nullptr;
    ds.n = 0;
    ds.d = nullptr;
}

template<typename T>
doos<T>& doos<T>::operator=(doos<T> &&ds) {
    if (this != &ds) {
        b = move(ds.b);

        delete c;
        c = ds.c;
        ds.c = nullptr;

        n = ds.n;
        ds.n = 0;

        delete[] d;
        d = ds.d;
        ds.d = nullptr;
    }
    return *this;
}
