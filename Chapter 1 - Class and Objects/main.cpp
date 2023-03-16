#include <iostream>
#include "Figures.h"

using namespace std;

// void Point2D::Set(double x0, double y0) {
// 	x = x0; y = y0;
// }

// void Point2D::Move(double dx, double dy) {
// 	x += dx; y += dy;
// }

// void Point2D::Scale(double sx, double sy) {
// 	x *= sx ; y *= sy;
// }

// void Circle::Set(double x0, double y0, double r) {
// 	Center.Set(x0, y0);
// 	if (r > 0) this->Radius = r;
// }

// void Circle::Move(double dx, double dy) {
// 	Center.Move(dx, dy);
// }

// double Circle::Area() {
// 	return PI * Radius * Radius;
// }

// double Circle::Perimeter() {
// 	return 2 * PI * Radius;
// }

// void inputCircleData(istream& inDevice, Circle& cir) {
// 	double x0, y0, r;
// 	inDevice >> x0 >> y0 >> r;	
// 	cir.Set(x0, y0, r);
// }

// void outputCircleInfo(ostream& outDevice, Circle& cir) {	
// 	outDevice << " - Area of circle = " << cir.Area() << "\n";
// 	outDevice << " - Perimeter of circle = " << cir.Perimeter() << "\n";
// }

istream& operator >> (istream& inDevice, Circle& cir) {
	double x0, y0, r;
	inDevice >> x0 >> y0 >> r;	
	cir.Set(x0, y0, r);
	return inDevice;
}

ostream& operator << (ostream& outDevice, Circle& cir) {	
	outDevice << " - Area of circle = " << cir.Area() << "\n";
	outDevice << " - Perimeter of circle = " << cir.Perimeter() << "\n";
	return outDevice;
}

int main() {
	Circle mycir;
	cout << "Input center and radius: ";
	// inputCircleData(cin, mycir);
	// outputCircleInfo(cout, mycir);
	cin >> mycir;
	cout << mycir;
	cin.get();
	return 0;
}
