#include <iostream>
#include <assert.h>
using namespace std;

class Array {
public:
    Array();
    Array(int);
    Array(int, int);
    ~Array();
protected:
    void init(const int*, int, int);
    int *p;
    int size;
    int col;
    int row;
    int error;
    virtual void Show() const = 0;
};

void Array::init(const int* pa, int m, int n) {
    int i, j;
    row = m , col = n;
    size = row * col;
    p = new int [size];
    assert(p != 0);
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j)
        p[i * n + j] = (pa != 0) ? pa[i * n + j] : 0;
    }
}

Array::Array() {
    init(0, 0, 0);
}

Array::Array(int m) {
    if(m < 0) {
        cerr << "\nIllegal size of vector";
        exit(EXIT_FAILURE);
    }
    init(0, m, 1);
}

Array::Array(int m, int n) {
    if(m < 0 || n < 0) {
        cerr << "\nIllegal size of matrix";
        exit(EXIT_FAILURE);
    }
    init(0, m, n);
}

Array::~Array() {
    delete[] p;
}

class Vector : public Array {
public:
    Vector()
      :Array() {}
    Vector(int m)
      :Array(m) {}
    Vector(const Vector& v) {
        init(v.p, v.row, 1);
    }
    ~Vector(){}
    int &operator()(int i) {
        if(i >= 1 && i <= size) {
            error = 0;
            return p[i - 1];
        }
        else {
            cout << "\nOperator()-Illegal size of vector, code=";
            error = 1;
            return error;
        }
     }

Vector &operator=(const Vector& v) {
    int i;
    if(this == &v) return *this;
    delete[] p;
    init(v.p, v.row, 1);
    return *this;
}

friend Vector operator+(Vector& v1, Vector& v2) {
    int i, ia, ib;
    ia = v1.row;
    ib = v2.row;
    if (ia == ib) {
        Vector vc(ia);
        for(i = 1; i <= ia; ++i)
        vc(i) = v1(i) + v2(i);
        return vc;
    }
    else {
        cout << "\nBad in vectors addition!";
        Vector vc(-1);
        return vc;
    }
}

friend Vector operator-(Vector& v1, Vector& v2) {
    int i, ia, ib ;
    ia = v1.row;
    ib = v2.row;
    if (ia == ib) {
        Vector vc(ia);
        for(i = 1; i <= ia; ++i)
        vc(i) = v1(i) - v2(i);
        return vc;
    }
    else {
        cout << "\nBad in vectors addition!";
        Vector vc(-1);
        return vc;
    }
}

void Show() const {
    cout << "\nVector values :" << endl;
    for(int i = 0; i < size; ++i)
        cout << p[i] << endl;
}
};

int main() {
    int ch, i, sz = 3;
    Vector first(sz), second(sz), third(sz), a, b, c;
    for(i = 1; i <= sz; ++i)
       first(i) = 1;
    for(i = 1; i <= sz; ++i)
       second(i) = 2;

    for(i = 1; i <= sz; ++i)
       third(i) = first(i) + second(i) ;

    a = third + first;
    b = a;
    third.Show();
    a.Show();
    b.Show();
    cout << "\nPress ENTER to continue..." << endl;
    ch = cin.get();
    c = a + b;
    Vector d = b + c;
    c.Show();
    cout << "\nPress ENTER to continue..." << endl;
    ch = cin.get();
    return EXIT_SUCCESS;
}