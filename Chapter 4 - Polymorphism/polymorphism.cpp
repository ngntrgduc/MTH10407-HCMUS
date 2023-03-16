#include <iostream>

class Base {
public:
    virtual std::string getName() const { return "Base"; }
};

class Derived: public Base {
public:
    virtual std::string getName() const { return "Derived"; }
};

class MoreDerived: public Derived {
public:
    virtual std::string getName() const { return "MoreDerived"; }
};

int main() {
    // Derived derived {};
    // Base& rBase{ derived };
    MoreDerived derived {};
    Base& rBase{ derived }; // rBase is a MoreDerived
    std::cout << "rBase is a " << rBase.getName() << '\n';
}