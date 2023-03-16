#include <iostream>

class A {
    int value { 0 };
public:
    void add(int val) { value += val; }
    friend void reset(A& a); // Make reset() a friend of this class
};
// reset() is now a friend of the A class
void reset(A& a) {
    a.value = 0; // And can access the private data of A objects
}
int main() {
    A a;
    a.add(5); // add 5 to a
    reset(a); // reset a to 0
}