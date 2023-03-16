#ifndef _PhanSo_h
#define _PhanSo_h

#include <iostream>

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

#endif