#include <iostream>
#include <string>

class Base {
public:
    virtual std::string getName() const { return "Base"; }
};

class Derived: public Base {
public:
    virtual std::string getName() const { return "Derived"; }
};

int main() {
    Derived derived {};
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName(); // rBase is a Base
}