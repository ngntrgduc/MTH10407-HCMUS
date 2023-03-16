#include <iostream>
// #include "Rectangle.h"
// #include "Square.h"

using namespace std;

class Rectangle {
protected: // protected allow child class of Rectangle can reusse this property
    float width, height;
public:
    Rectangle() {};
    Rectangle(float w, float h) { width = w; height = h; };
    float Area() { return width * height; };
    virtual void Input(std::istream& inDevice) { inDevice >> width >> height; }; // Polymorphism using virtual
};

class Square : public Rectangle {
public:
    Square(float a = 0) { width = height = a; };
    void Input(std::istream& inDevice) { inDevice >> width; height = width; };
};

int main() {
    Rectangle Rec; 
    Square Sq;
    Rectangle* pRec;
    // Square Sq(4);
    // pRec = &Sq;
    // cout << pRec.Area() << "\n";
    // pRec = new Square(1);
    pRec = &Rec;
    pRec->Input(cin);
    // Rec.Input(cin);
    cout << Rec.Area() << "\n";

    pRec = &Sq;
    pRec->Input(cin); // Call Input() of Rectangle class
    cout << Sq.Area() << "\n";
    return 0;
}