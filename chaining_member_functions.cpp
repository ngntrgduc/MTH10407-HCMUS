#include <iostream>

class Calc {
    int m_value{0};
public:
    // void add(int value) { m_value += value; }
    // void sub(int value) { m_value -= value; }
    // void mult(int value) { m_value *= value; }

    // Chainable function
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};

int main() {
    Calc calc{};
    // calc.add(5); // returns void
    // calc.sub(3); // returns void
    // calc.mult(4); // returns void

    calc.add(5).sub(3).mult(4); // returning *this, reference to calc
    std::cout << calc.getValue() << '\n';
}