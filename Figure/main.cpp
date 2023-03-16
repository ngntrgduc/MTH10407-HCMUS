#include <iostream>
using namespace std;

class Figure {
public:
    Figure() {};
    virtual void Input(istream& inDev) {};
    virtual float Area() { return 0; }
    virtual string className() = 0;
};

class Rectangle : public Figure {
protected:
    float width, height;
public:
    Rectangle() {}
    Rectangle(float w, float h) { width = w; height = h; }
    float Area() { return width * height; }
    virtual void Input(std::istream& inDevice) { inDevice >> width >> height; }
    virtual string className() { return "Rectangle"; }
};

class Square : public Rectangle {
public:
    Square(float a = 0) { width = height = a; }
    void Input(std::istream& inDevice) { inDevice >> width; height = width; }
    virtual string className() { return "Square"; }
};

class Ellipse : public Figure {
protected:
    float Ra, Rb;
public:
    Ellipse(float a = 0, float b = 0) { Ra = a; Rb = b; }
    virtual void Input(istream& inDevice) { inDevice >> Ra >> Rb; }
    virtual float Area() { return 3.14 * Ra * Rb; }
    virtual string className() { return "Ellipse"; }
};

class Circle : public Ellipse {
public:
    Circle(float r = 0): Ellipse(r, r) {} // Neu dung { Ellipse(r,r)} hoac {Ra=Rb=r} thi constructor cua Ellipse se duoc goi 2 lan
    virtual void Input(istream& inDevice) { inDevice >> Ra; Rb = Ra; }
    virtual string className() { return "Circle"; }
};

class Triangle : public Figure {
protected:
    float basesize, height;
public:
    Triangle(float a = 0, float h = 0) { basesize = a; height = h; }
    virtual void Input(istream& inDevice) { inDevice >> basesize >> height; }
    virtual float Area() { return basesize * height / 2; }
    virtual string className() { return "Triangle"; }
};

Figure* figMaxArea(Figure* figs[], int nFig) {
    Figure* figMax = NULL;
    if (nFig > 0) {
        figMax = figs[0];
        for (int i = 0; i < nFig; i++) {
            if (figMax->Area() < figs[i]->Area()) {
                figMax = figs[i];
            }
        }
    }
    return figMax;
}

int main() {
    Figure* Figs[] = { new Rectangle(9, 8), new Square(5), new Ellipse(4,3), new Circle(4), new Triangle(10, 6) };
    int nFig = sizeof(Figs) / sizeof(Figure);
    // Figure* aFig = figMaxArea(Figs, nFig);
    // if (aFig != NULL) { cout << aFig->Area() << '\n'; }
    for (int i = 0; i < nFig; i++) {
        cout << Figs[i]->className() << ", area = ";
        cout << Figs[i]->Area() << "\n";
    }    
    return 0;
}

