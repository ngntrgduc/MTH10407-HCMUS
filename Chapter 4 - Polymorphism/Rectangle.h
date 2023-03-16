#ifndef _Rectangle_h
#define _Rectangle_h

#include <iostream>

class Rectangle {
protected: 
    float width, height;
public:
    Rectangle();
    Rectangle(float w, float h);
    float Area();
    void Input(std::istream& inDevice);
};

#endif