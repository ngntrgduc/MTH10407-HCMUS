// Athor: Nguyen Trung Duc
#include <iostream>
#include <vector>

using namespace std;

// ---------- Cau 1 ----------
class Point {
    double x, y;
public:
    Point(double x0 = 0, double y0 = 0) { x = x0; y = y0; }
    // Cộng
    Point add(Point& point) {
        x += point.x;
        y += point.y;
        return *this;
    }
    // Trừ
    Point subtract(Point& point) {
        x -= point.x;
        y -= point.y;
        return *this;
    }
    // Nhân 1 vô hướng với 1 điểm
    Point scalar(double s) {
        x *= s;
        y *= s;
        return *this;
    }
    // Tích vô hướng
    double dotProduct(Point& point) {
        return x*point.x + y*point.y;
    }

    // Hoặc dùng operator overloading
    friend Point operator+(const Point& point1, const Point& point2) {
        Point temp;
        temp.x = point1.x + point2.x;
        temp.y = point1.y + point2.y;
        return temp;
    }
    Point& operator+=(Point& point) {
        x = x + point.x;
        y = y + point.y;
        return *this;
    }
    friend Point operator-(const Point& point1, const Point& point2) {
        Point temp;
        temp.x = point1.x - point2.x;
        temp.y = point1.y - point2.y;
        return temp;
    }
    Point& operator-=(Point& point) {
        x = x - point.x;
        y = y - point.y;
        return *this;
    }
    // Nhân 1 điểm với 1 vô hướng
    friend Point operator*(Point& point, int scalar) {
        Point temp;
        temp.x = point.x * scalar;
        temp.y = point.y * scalar;
        return temp;
    }
    // Nhân 1 vô hướng với 1 điểm
    friend Point operator*(int scalar, Point& point) {
        Point temp;
        temp.x = point.x * scalar;
        temp.y = point.y * scalar;
        return temp;
    }
    // Tích vô hướng
    friend double operator*(const Point& point1, const Point& point2) {
        return point1.x*point2.x + point1.y*point2.y;
    }
    // Hàm lấy giá trị
    void get() { cout << "(" << x << ", " << y << ")\n"; }
};

void cau1() {
    Point a(1,2), b(1,1);
    cout << "a = "; a.get();
    cout << "b = "; b.get();
    Point c = a + b; // Point c = a.add(b);, a lúc này sẽ là a cộng thêm b
    // Point c = a.add(b); a.get(); c.get();
    cout << "c = a + b = "; c.get();
    a += b; // a.add(b);
    cout << "a += b => "; a.get();
    Point d = a - b; // Point d = a.subtract(b);
    cout << "d = a - b = "; d.get();
    d -= b; // d.subtract(b);
    cout << "d -= b => "; d.get();
    Point e1 = d * 2; // d.scalar(2);
    cout << "e1 = d * 2 = "; e1.get();
    Point e2 = 2 * d; // d.scalar(2);
    cout << "e2 = 2 * d = "; e2.get();
    double dotProduct = e1 * e2;
    cout << "e1 * e2 = " << dotProduct; // e1.dotProduct(e2);
}


// ---------- Cau 2 ----------
class Stack {
    vector<int> data;
public:
    bool isEmpty() const { return data.size() <= 0; }

    void push(int element) {
        data.push_back(element);
    }
    
    int pop() {
        if (!isEmpty()) {
            int top = data.back();
            data.pop_back();
            return top;
        }
    }

    int top() {
        if (!isEmpty()) 
            return data.back();
    }

    // void printStack() {
    //     for (int i = 0; i < data.size(); i++) { cout << data[i] << ' '; }
    //     cout << '\n';
    // }
};

void cau2() {
    Stack s;
    int n, i, count, top;
    cout << "Nhap so nguyen n : "; cin >> n;
    // Phân tích thừa số nguyên tố và chuyển qua Stack
    for (int i = 2; i <= n; i++) { 
        count = 0;
        while (n % i == 0) {
            s.push(i);
            n /= i;
            count++;
        }
    }

    cout << "Sau khi phan tich: ";
    while (!s.isEmpty()) {
        count = 1;
        top = s.top();
        s.pop();
        while (top == s.top()) {
            count++;
            s.pop();
        }
        // Xử lý cái dấu nhân với cái dấu mũ :)
        // if (count == 1) { 
        //     if (s.isEmpty()) { cout << top; }  
        //     else { cout << top << " * "; }
        // } else {
        //     if (s.isEmpty()){ cout << top << "^" << count; }  
        //     else { cout << top << "^" << count << " * "; }
        // }
        string delimiter = (s.isEmpty()) ? "" : " * ";
        if (count == 1) { 
            cout << top << delimiter;
        } else {
            cout << top << "^" << count << delimiter;
        }
    }
}


// ---------- Cau 3 ----------
class Shape {
public:
    Shape() {};
    virtual bool isSymmetry() = 0;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w = 0, double h = 0) { width = w; height = h; }
    bool isSymmetry() { return true; }    
};

class Ellipse : public Shape {
protected:
    double Ra, Rb;
public:
    Ellipse(double a = 0, double b = 0) { Ra = a; Rb = b; }
    bool isSymmetry() { return true; }
};

class Circle : public Ellipse {
public:
    Circle(double r = 0): Ellipse(r, r) {} // Nếu dùng { Ellipse(r, r) } hoac { Ra = Rb = r } thì constructor của Ellipse sẽ được gọi 2 lần
    bool isSymmetry() { return true; }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a0 = 0, double b0 = 0, double c0 = 0) { a = a0; b = b0; c = c0; }
    virtual bool isSymmetry() {
        return ((a == c) or (a == b) or (b == c));
    }
};

void cau3() {
    Shape* shapes[] = { new Rectangle(1, 2), new Ellipse(2,3), new Circle(4), \
                        new Triangle(1, 2, 2), new Triangle(1, 2, 3) };
    int numberOfShapes = sizeof(shapes) / sizeof(Shape), count = 0;
    for (int i = 0; i < numberOfShapes; i++) {
        if (shapes[i]->isSymmetry()) count++;
    }
    cout << "Co " << count << " hinh doi xung trong danh sach"; 
}


// ---------- MAIN ----------
int main() {
    // cau1();
    cau2();
    // cau3();
}