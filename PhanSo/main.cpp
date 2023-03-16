#include <iostream>
// #include "PhanSo.h"

using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo(int, int);
    PhanSo& operator+=(const PhanSo&);
    const PhanSo operator+(const PhanSo&) const;
    bool operator==(const PhanSo&) const;
    PhanSo& operator++();   // Prefix ++
    PhanSo operator++(int); // Postfix ++
    PhanSo refactor();
    operator int() const { return tu / mau; }

friend ostream& operator<<(ostream &out, const PhanSo& src);
};

PhanSo::PhanSo(int t=0, int m=1) { tu = t; mau = m; }

PhanSo& PhanSo::operator+=(const PhanSo& src) {
    if (mau == src.mau) {
        tu = tu + src.tu;
    } else if (mau % src.mau == 0) {
        tu = tu + src.tu * (mau % src.mau);
        mau = mau;
    } else if (src.mau % mau == 0) {
        tu = src.tu + tu * (src.mau % mau);
        mau = src.mau;
    } else {
        tu = tu * src.mau + src.tu * mau;
        mau = mau * src.mau;
    }
    return *this;
}

const PhanSo PhanSo::operator+(const PhanSo& src) const {
    PhanSo temp;
    if (mau == src.mau) {
        temp.tu = tu + src.tu;
        temp.mau = mau;
    } else if (mau % src.mau == 0) {
        temp.tu = tu + src.tu * (mau % src.mau);
        temp.mau = mau;
    } else if (src.mau % mau == 0) {
        temp.tu = src.tu + tu * (src.mau % mau);
        temp.mau =src.mau;
    } else {
        temp.tu = tu * src.mau + src.tu * mau;
        temp.mau = mau * src.mau;
    }
    return temp;
}

PhanSo& PhanSo::operator++() {
    tu = tu + mau;
    return *this;
}

PhanSo PhanSo::operator++(int) {
    PhanSo temp = *this;
    ++(*this);
    return temp;
}

bool PhanSo::operator==(const PhanSo& src) const {
    return (tu == src.tu) && (mau == src.mau);
}

PhanSo PhanSo::refactor() {
    if (tu == mau) {
        tu = mau = 1;
    } else if (tu % mau == 0) {
        tu = tu / mau;
        mau = 1;
    } else if (mau % tu == 0) {
        tu = 1;
        mau = mau / tu;
    } 
    return *this;
}

ostream& operator<<(ostream &out, const PhanSo& src) {
    if (src.mau == 1) out << src.tu;
    else out << src.tu << "/" << src.mau;
    return out;
}

int main() {
    PhanSo a(1, 2), b(2, 5);
    cout << a << "\n";
    cout << ++a << "\n";
    cout << a << "\n"; 
    cout << a++ << "\n";
    cout << a << "\n";
    // cout << a << "\n";
    // cout << b << "\n";
    // cout << a + b << "\n";
    // PhanSo d(9, 10), e(1, 10);
    // cout << d << "\n";
    // d += e;
    // cout << d << "\n";

    // cout << d.PhanSo::refactor() << "\n";
    // PhanSo f(90, 10);
    // int x = f;
    // int y = int(f);
    // int z = (int)f;
    // cout << f << "\n";
    // cout << x << "\n";
    // cout << y << "\n";
    // cout << z << "\n";
}