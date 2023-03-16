// Athor: Nguyen Trung Duc
#include <iostream>
#include <vector>

using namespace std;

// ---------- Cau 1 ----------
class Point {
    double x, y;
public:
    // Point() {};
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
    // Point& operator=(Point point)
    // Point& operator+(Point point)
    // Point& operator-(Point point) 
    // Point& operator*(int scalar)
    // Point& operator*(Point point)

    // Hàm lấy giá trị
    void get() { cout << "(" << x << ", " << y << ")\n"; }
};

int main() {
    Point a(1,2), b(3,4), c(1,1);
    cout << "a = "; a.get();
    cout << "b = "; b.get();
    // a.add(b);
    a.get();
    c.scalar(5);
    c.get();
    // a.subtract(c);
    a.get();
    cout << "a * b = "<< a.dotProduct(b);
}


// ---------- Cau 2 ----------
class Stack {
    vector<int> data;
    int top;
public:
    Stack() {top = 0;}
    bool empty() {
        return top == 0;
    }
    void push(Stack& s, int value) {
        data[++top];
    }
    void push(Stack& s, int value) {
        // data[++top] = value;
        data.push_back(value);
        ++top;
    }
    int pop(Stack& s) {
        return data[top--];
    }
};

// int main() {
//     struct Stack s;
//     for(int i = 0; i <= MAX; i++) 
//         if (!full(&s)) push(&s, i);

// ---------- Cau 3 ----------
class Shape {

};