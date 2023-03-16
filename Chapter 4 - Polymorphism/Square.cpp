#include "Square.h"

Square::Square(float a) { width = height = a; }

void Square::Input(std::istream &inDevice) { inDevice >> width; height = width; }